#!/usr/bin/env python3
# The fact that this solution exists saddens me greatly

import math

n,m,k=[int(i) for i in input().split()]

freq = []

tot = pow(m,n)
for t in range(n, n * m + 1):
    s = 0
    for i in range((t - n) // m + 1):
        s += math.comb(n,i)*math.comb(t - i * m - 1, n - 1)*(1 if i%2==0 else -1)
    freq.append(s)


freq = sorted(freq, reverse=True)
ans = 0
for i in range(k):
    ans += freq[i]
print(f'{ans/tot:.15f}')
