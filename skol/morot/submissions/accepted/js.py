#!/usr/bin/env python3

C = 40
T, M = map(int, input().split())
TE, ME = 0, 0

t = 0
while C:
    ta, ma = t % T == 0, t % M == 0
    if ta and ma and C == 1: break
    if ta:
        C -= 1
        TE += 1
    if ma:
        C -= 1
        ME += 1

    t += 1
print(TE, ME)
