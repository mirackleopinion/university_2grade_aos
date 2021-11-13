# DASHA TEREKHOVA K-20 LAB 3

STACK_SIZE = 8
MANTISS_WIDTH = 10
EXPONENT_WIDTH = 10


stack = []


def push(x):
    if len(stack) == STACK_SIZE:
        raise ValueError("stack overflow")
    stack.append(x)


def pop():
    if len(stack) == 0:
        raise ValueError("stack is empty")
    return stack.pop()


def float_to_ieee754():
    x = float(pop())


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
