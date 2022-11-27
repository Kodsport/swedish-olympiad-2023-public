#!/usr/bin/env python3
A = int(input())
N = int(input())

L = sorted(map(int, input().split()))

l = 0
r = N - 1
res = 0
while l < r:
    if L[l] * L[r] >= A:
        l += 1
        r -= 1
        res += 1
    else:
        l += 1

print(res)
