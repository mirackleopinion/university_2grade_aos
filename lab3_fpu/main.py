# DASHA TEREKHOVA K-20 LAB 3
# варіант 7x.9m.9V
# формат ЧПТ 7 бітів для характеристики
# 9 явних біти у мантисі плюс знаковий біт;
# 9 варіант із таблиці формул для обрахунку співпроцесором.
# 7*x*(sin x/cos y)
from math import sin, cos

STACK_SIZE = 8
stack = []

# float
# MANTISS_WIDTH = 23
# EXPONENT_WIDTH = 8

# double
# MANTISS_WIDTH = 52
# EXPONENT_WIDTH = 11

# variant 7.9
MANTISS_WIDTH = 9
EXPONENT_WIDTH = 7

WIDTH = 1 + EXPONENT_WIDTH + MANTISS_WIDTH
EXP_SHIFT = 2 ** (EXPONENT_WIDTH - 1) - 1
MAXIMUM_EXP = 2 ** EXPONENT_WIDTH - 1 - EXP_SHIFT
MINIMUM_EXP = -EXP_SHIFT


def set_exp(arr, exp):
    exp += EXP_SHIFT
    pos = EXPONENT_WIDTH
    while exp:
        arr[pos] = exp % 2
        pos -= 1
        exp = exp // 2


def is_zero(x):
    _, e, m = ieee754_cutter(x)

    if m != 0:
        return False

    if e != MINIMUM_EXP:
        return False

    return True


def is_infinity(x):
    _, e, m = ieee754_cutter(x)

    if m != 0:
        return False

    if e != MAXIMUM_EXP:
        return False

    return True


def is_nan(x):
    if is_infinity(x):
        return False

    e = ieee754_cutter(x)[1]
    return e == MAXIMUM_EXP


def is_denormalized(x):
    if is_zero(x):
        return False

    e = ieee754_cutter(x)[1]
    return e == MINIMUM_EXP


def ieee754_to_float(x):
    S, E, M = ieee754_cutter(x)
    if is_denormalized(x):
        return ((-1) ** S) * (2 ** E) * (M / (2 ** MANTISS_WIDTH))
    else:
        return ((-1) ** S) * (2 ** E) * (1 + M / (2 ** MANTISS_WIDTH))


def float_to_ieee754(x):
    return str_to_ieee754(f'{x:.15f}')


def ieee754_cutter(x):
    s = x[0]

    e = 0
    for i in range(1, EXPONENT_WIDTH + 1):
        e *= 2
        e += x[i]

    e -= EXP_SHIFT

    m = 0
    for i in range(EXPONENT_WIDTH + 1, WIDTH):
        m *= 2
        m += x[i]

    return s, e, m


def ieee754_to_str(x):
    result = []
    result.append(str(x[0]))  # sign
    result.append(''.join(map(str, x[1:EXPONENT_WIDTH + 1])))  # exponenta

    result.append(''.join(map(str, x[EXPONENT_WIDTH + 1:])))  # mantissa

    mantiss_forgotten_bit = ''

    if is_zero(x):
        mantiss_forgotten_bit = '0'
        if x[0] == 1:
            result.append('-0.0')
        else:
            result.append('+0.0')
    elif is_infinity(x):
        mantiss_forgotten_bit = '1'
        if x[0] == 1:
            result.append('-∞')
        else:
            result.append('+∞')
    elif is_nan(x):
        mantiss_forgotten_bit = '0'
        result.append('NaN')
    else:
        if is_denormalized(x):
            mantiss_forgotten_bit = '0'
        else:
            mantiss_forgotten_bit = '1'
        result.append(f'{ieee754_to_float(x):.25f}')

    result.insert(2, mantiss_forgotten_bit)
    return ' '.join(result)


def str_to_ieee754(a):
    result = [0] * WIDTH
    sign = 0

    if a.startswith("-"):
        sign = 1
        a = a[1:]
    elif a.startswith("+"):
        a = a[1:]

    if '.' in a:
        a1, a2 = a.split('.')
    else:
        a1, a2 = a, '0'

    _divider = 10 ** len(a2)

    a1, a2 = int(a1), int(a2)

    _before = []
    while a1:
        _before.insert(0, a1 % 2)
        a1 = a1 // 2

    if len(_before) > MAXIMUM_EXP:  # +/- inf
        result[0] = sign
        set_exp(result, MAXIMUM_EXP)
    else:
        _after = []

        while a2 and len(_after) < EXP_SHIFT + MANTISS_WIDTH + 1:
            a2 *= 2
            _after.append(a2 // _divider)
            a2 %= _divider

        if _before:
            exponent = len(_before) - 1  # |number| >= 1
            result[0] = sign
            set_exp(result, exponent)
            temp = _before[1:] + _after
            for i in range(min(len(temp), MANTISS_WIDTH)):
                result[1 + EXPONENT_WIDTH + i] = temp[i]
        else:
            exponent = -1

            for i in range(len(_after)):
                if _after[i] == 1:
                    exponent = i + 1
                    break

            if exponent == -1 or exponent > EXP_SHIFT + MANTISS_WIDTH:  # +/- 0.0
                result[0] = sign
            elif exponent > EXP_SHIFT:  # denormalized
                result[0] = sign
                for i in range(min(len(_after) - EXP_SHIFT, MANTISS_WIDTH)):
                    result[1 + EXPONENT_WIDTH + i] = _after[EXP_SHIFT + i]
            else:  # |number| < 1
                result[0] = sign
                set_exp(result, -exponent)
                for i in range(min(len(_after) - exponent, MANTISS_WIDTH)):
                    result[1 + EXPONENT_WIDTH + i] = _after[exponent + i]

    return result


def show_stack():
    print('Stack:')
    for i in reversed(range(STACK_SIZE)):
        print(f'{i}: {ieee754_to_str(stack[i]) if i < len(stack) else "-"}')
    print()


def fpush(x, verbose=True):
    if len(stack) == STACK_SIZE:
        raise ValueError("stack overflow")

    stack.append(x)

    if verbose:
        print(f'Push: {ieee754_to_str(x)}')
        show_stack()


def fpop(verbose=True):
    if len(stack) == 0:
        raise ValueError("stack is empty")

    result = stack.pop()

    if verbose:
        print(f'Pop: {ieee754_to_str(result)}')
        show_stack()

    return result


def fmul():
    a = fpop(verbose=False)
    b = fpop(verbose=False)

    if is_nan(a) or is_nan(b):
        raise ValueError('Multiplication to NaN')

    if is_infinity(a) or is_infinity(b):
        raise ValueError('Multiplication to infinity')

    c = float_to_ieee754(ieee754_to_float(a) * ieee754_to_float(b))
    fpush(c, verbose=False)
    print(f'fmul {ieee754_to_float(a)} * {ieee754_to_float(b)} = {ieee754_to_float(c)} ')
    show_stack()


def fdiv():
    a = fpop(verbose=False)
    b = fpop(verbose=False)

    if is_nan(a) or is_nan(b):
        raise ValueError('Divide with NaN')

    if is_infinity(a) or is_infinity(b):
        raise ValueError('Divide with infinity')

    if is_zero(b) or is_denormalized(b):
        raise ZeroDivisionError('Divide with zero or denormalized')

    c = float_to_ieee754(ieee754_to_float(a) / ieee754_to_float(b))
    fpush(c, verbose=False)
    print(f'fdiv {ieee754_to_float(a)} / {ieee754_to_float(b)} = {ieee754_to_float(c)} ')
    show_stack()


def fsin():
    x = fpop(verbose=False)

    if is_nan(x):
        raise ValueError('sin(NaN)')

    if is_infinity(x):
        raise ValueError('sin(infinity)')

    c = float_to_ieee754(sin(ieee754_to_float(x)))
    fpush(c, verbose=False)
    print(f'fsin sin({ieee754_to_float(x)}) = {ieee754_to_float(c)} ')
    show_stack()


def fcos():
    x = fpop(verbose=False)

    if is_nan(x):
        raise ValueError('cos(NaN)')

    if is_infinity(x):
        raise ValueError('cos(infinity)')

    c = float_to_ieee754(cos(ieee754_to_float(x)))
    fpush(c, verbose=False)
    print(f'fsin cos({ieee754_to_float(x)}) = {ieee754_to_float(c)} ')
    show_stack()


print(f's {"e" * EXPONENT_WIDTH} M.{"m" * MANTISS_WIDTH} decimal value')

z = [0] + [0] * (EXPONENT_WIDTH - 1) + [1] + [0] * MANTISS_WIDTH
print(f'{ieee754_to_str(z):70} мінімальне за абсолютною величиною ненульове представлення')

z = [0] + [1] * (EXPONENT_WIDTH - 1) + [0] + [1] * MANTISS_WIDTH
print(f'{ieee754_to_str(z):70} максимальне додатнє представлення (2 - 2^(-{MANTISS_WIDTH})) * 2^{MAXIMUM_EXP - 1}')

z = [1] + [1] * (EXPONENT_WIDTH - 1) + [0] + [1] * MANTISS_WIDTH
print(f'{ieee754_to_str(z):70} мінімальне від’ємне преставлення')

z = str_to_ieee754("1.0")
print(f'{ieee754_to_str(z):70} число +1,0Е0')

z = [0] + [1] * EXPONENT_WIDTH + [0] * MANTISS_WIDTH
print(f'{ieee754_to_str(z):70} значення +∞')

z = [1] + [1] * EXPONENT_WIDTH + [0] * MANTISS_WIDTH
print(f'{ieee754_to_str(z):70} значення -∞')

z = [0] + [0] * (EXPONENT_WIDTH ) + [0] * (MANTISS_WIDTH - 1) + [1]
print(f'{ieee754_to_str(z):70} будь-який варіант для ненормалізованого ЧПТ')

z = [0] + [0] * (EXPONENT_WIDTH + MANTISS_WIDTH )
print(f'{ieee754_to_str(z):70} +0.0')

z = [1] + [0] * (EXPONENT_WIDTH + MANTISS_WIDTH )
print(f'{ieee754_to_str(z):70} -0.0')

z = [0] + [1] * (EXPONENT_WIDTH ) + [0] * (MANTISS_WIDTH - 1) + [1]
print(f'{ieee754_to_str(z):70} будь-який варіант для NaN-значення')


x = input("x:")
y = input("y:")

fpush(str_to_ieee754(y))    # y
fcos()                      # cos(y)
fpush(str_to_ieee754('7'))  # 7                       | cos(y)
fpush(str_to_ieee754(x))    # x                       | 7      | cos(y)
fmul()                      # x * 7                   | cos(y)
fpush(str_to_ieee754(x))    # x                       | x * 7  | cos(y)
fsin()                      # sin(x)                  | x * 7  | cos(y)
fmul()                      # sin(x) * x * 7          | cos(y)
fdiv()                      # sin(x) * x * 7 / cos(y)

print('Checking:')
f_x = float(x)
f_y = float(y)
print(7.0 * f_x * sin(f_x) / cos(f_y))
