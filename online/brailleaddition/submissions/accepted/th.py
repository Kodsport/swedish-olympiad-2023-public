#!/usr/bin/env python3

import sys

REPRESENTATION = (
    ".***..",
    "*.....",
    "*.*...",
    "**....",
    "**.*..",
    "*..*..",
    "***...",
    "****..",
    "*.**..",
    ".**...",
)

DIGIT = {s: i for (i, s) in enumerate(REPRESENTATION)}


def i2ss(number):
    res = []
    if not number: res = [REPRESENTATION[0]]
    while number:
        res.append(REPRESENTATION[number % 10])
        number //= 10
    return list(reversed(res))


def ss2i(ss):
    res = 0
    for i in range((len(ss[0]) + 1) // 3):
        res *= 10
        res += DIGIT[''.join(s[3 * i : 3 * i + 2] for s in ss)]
    return res


lines = sys.stdin.readlines()
output = i2ss(sum(map(ss2i, zip(lines[1::4], lines[2::4], lines[3::4]))))

for idx in [0, 2, 4]:
    print(" ".join(x[idx:][:2] for x in output))
