#!/usr/bin/env python3
import collections

N = int(input())

atob = {}
btoa = collections.defaultdict(list)

def translate(w):
    for p in btoa[atob[w]]:
        if p != w:
            return p
    return w

for _ in range(N):
    a, b = input().split()
    atob[a] = b
    btoa[b].append(a)

M = int(input())

W = input().split()
W = [translate(w) for w in W]
print(*W)
