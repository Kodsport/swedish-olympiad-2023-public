#!/usr/bin/env python3
# Should get 40
n,m,k=[int(i) for i in input().split()]

freq = [0] * (n*m+1)

def recur(n_roll, msum):
    if n_roll==n:
        freq[msum]+=1
        return
    for i in range(1,m+1):
        recur(n_roll+1,msum+i)

recur(0,0)

s = sum(freq)
freq = [i/float(s) for i in freq]
freq = sorted(freq, reverse=True)
ans = 0
for i in range(k):
    ans += freq[i]
print(f'{ans:.15f}')
