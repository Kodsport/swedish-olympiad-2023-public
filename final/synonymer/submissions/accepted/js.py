#!/usr/bin/env python3
import collections

N = int(input())

atob = collections.defaultdict(list)
btoa = collections.defaultdict(list)

def translate(w):
    matches = set([a for b in atob[w] for a in btoa[b]])
    for p in matches:
        if p != w:
            return p
    return w

for _ in range(N):
    a, b = input().split()
    atob[a].append(b)
    btoa[b].append(a)

M = int(input())

W = input().split()
W = [translate(w) for w in W]
print(*W)
