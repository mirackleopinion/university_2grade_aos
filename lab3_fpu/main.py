# DASHA TEREKHOVA K-20 LAB 3

STACK_SIZE = 8
MANTISS_WIDTH = 10
EXPONENT_WIDTH = 10
WIDTH = 1 + EXPONENT_WIDTH + MANTISS_WIDTH
EXP_SHIFT = 2 ** (EXPONENT_WIDTH - 1)

stack = []


def push(x):
    if len(stack) == STACK_SIZE:
        raise ValueError("stack overflow")
    stack.append(x)


def pop():
    if len(stack) == 0:
        raise ValueError("stack is empty")
    return stack.pop()


def str_to_ieee754(a):
    # TODO sign
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

    _after = []
    while a2 and len(_after) < width:
        a2 *= 2
        _after.append(a2 // _divider)
        a2 %= _divider

    # TODO +-0

    print(f"{''.join(map(str, _before))}.{''.join(map(str, _after))}")

    # TODO IEEE


def ieee754_to_str():
    pass


def add():
    x = pop()
    y = pop()
    z = x + y  # TODO
    push(z)


push(1)
push(1)
add()
print(pop())
