# Terekhova Daria K-20
# 3. 3-адресна Результат розміщується у 1-му операнді
# 8. 26-бітні
# 9. X or Y (логічне додавання).

import random

WIDTH = 26


def tick():
    input("Press Enter")


def prepare(_p, cmd):
    _p['IR'] = cmd
    _p['TC'] += 1


def to_register(s):
    x = int(s)
    data = to_binary(abs(x))

    if x < 0:
        for i in range(WIDTH):
            if data[i] == 0:
                data[i] = 1
            else:
                data[i] = 0

        owerflow = 1

        for i in range(WIDTH):
            x = data[i] + owerflow
            data[i] = x % 2
            owerflow = x // 2

    return data


def to_binary(x):
    data = [0] * WIDTH
    for i in range(WIDTH):
        data[i] = x % 2
        x = x // 2
    return data


def execute(_p):
    cmd = _p['IR']

    if cmd.startswith('MOV '):
        dst, src = cmd.replace('MOV ', '').split(', ')
        _p[dst] = get_data(_p, src)

        set_ps(_p, dst)

    elif cmd.startswith('OR '):
        dst, arg1, arg2 = cmd.replace('OR ', '').split(', ')
        b_arg1 = get_data(_p, arg1)
        b_arg2 = get_data(_p, arg2)

        data = [0] * WIDTH
        for i in range(WIDTH):
            data[i] = b_arg1[i] | b_arg2[i]
        _p[dst] = data

        set_ps(_p, dst)

    _p['TC'] += 1
    _p['PC'] += 1


def set_ps(_p, dst):
    if _p[dst][WIDTH - 1] == 0:
        _p['PS'] = '+'
    else:
        _p['PS'] = "-"


def get_data(_p, src):
    if src in ['R1', 'R2', 'R3']:
        data = _p[src]
    else:
        data = to_register(src)
    return data


def show(_p):
    print()
    for k, v in _p.items():
        if k not in ['R1', 'R2', 'R3']:
            print(f'{k}: {v}')
        else:
            print(f'{k}: {" ".join(map(str, v[::-1]))}')
    print()


p = {
    'R1': [random.choice([0, 1]) for _ in range(WIDTH)],
    'R2': [random.choice([0, 1]) for _ in range(WIDTH)],
    'R3': [random.choice([0, 1]) for _ in range(WIDTH)],
    'IR': "",
    'PS': "+",
    'PC': 0,
    'TC': 0
}


for line in open('commands.txt').readlines():
    print('Prepare:')
    prepare(p, line.strip())
    show(p)
    tick()

    print('Execute:')
    execute(p)
    show(p)
    tick()
