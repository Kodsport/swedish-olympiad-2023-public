#!/usr/bin/env python3
N, S = map(int, input().split())
trees = []
for i in range(N):
    trees.append(list(map(int, input().split())))

lo = -1
hi = 10 ** 9

while hi - lo > 1:
    mid = (lo + hi) // 2
    sm = 0
    for l, v, t in trees:
        sm += l
        sm += v * min(t, mid)
    if sm >= S: hi = mid
    else: lo = mid
print(hi)
