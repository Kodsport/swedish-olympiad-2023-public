#!/usr/bin/python3

import random

n, t = map(int, input().split())

X = [random.randint(1, 10**9) for _ in range(n)]
X.sort()

print('!',*X)
