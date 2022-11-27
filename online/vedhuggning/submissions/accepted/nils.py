#!/usr/bin/env python3

n, s = map(int,input().split())

L = []
V = []
T = []
for _ in range(n):
    l,v,t = map(int,input().split())
    L.append(l)
    V.append(v)
    T.append(t)

lo = -1
hi = 10**9+2

while lo < hi-1:
    mid = (lo+hi) // 2
    res = 0
    for i in range(n):
        res += L[i] + V[i] * min(T[i], mid)
    if res >= s:
        hi = mid
    else:
        lo = mid
print(hi)
