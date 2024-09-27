#!/usr/bin/env python3
# Should get 20

n,m,k=[int(i) for i in input().split()]

freq = [0] * (n*m+1)
for i in range(1,m+1):
    for j in range(1,m+1):
        freq[i+j]+=1

s = sum(freq)
freq = [i/float(s) for i in freq]
freq = sorted(freq, reverse=True)
ans = 0
for i in range(k):
    ans += freq[i]
print(f'{ans:.15f}')
