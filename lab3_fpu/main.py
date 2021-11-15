# DASHA TEREKHOVA K-20 LAB 3
# варіант 7x.9m.9V
# формат ЧПТ 7 бітів для характеристики
# 9 явних біти у мантисі плюс знаковий біт;
# 9 варіант із таблиці формул для обрахунку співпроцесором.
# 7*x*(sin x/cos y)

STACK_SIZE = 8
stack = []

# float
# MANTISS_WIDTH = 23
# EXPONENT_WIDTH = 8

# double
# MANTISS_WIDTH = 52
# EXPONENT_WIDTH = 11

MANTISS_WIDTH = 9
EXPONENT_WIDTH = 7

WIDTH = 1 + EXPONENT_WIDTH + MANTISS_WIDTH
EXP_SHIFT = 2 ** (EXPONENT_WIDTH - 1) - 1


def push(x):
    if len(stack) == STACK_SIZE:
        raise ValueError("stack overflow")
    stack.append(x)


def pop():
    if len(stack) == 0:
        raise ValueError("stack is empty")
    return stack.pop()


def set_exp(arr, exp):
    exp += EXP_SHIFT
    pos = EXPONENT_WIDTH
    while exp:
        arr[pos] = exp % 2
        pos -= 1
        exp = exp // 2


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

    if len(_before) > EXP_SHIFT:  # +/- inf
        result[0] = sign
        set_exp(result, 2 ** EXPONENT_WIDTH - 1 - EXP_SHIFT)
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

        print(f"{'-' if sign else '+'}{''.join(map(str, _before))}.{''.join(map(str, _after))} ")

    return result


def ieee754_to_str():
    pass


def add():
    x = pop()
    y = pop()
    z = x + y  # TODO
    push(z)

# print(str_to_ieee754('-0.0000000000000000000005'))
print(str_to_ieee754('155.625'))
# print(str_to_ieee754('-0.05'))
