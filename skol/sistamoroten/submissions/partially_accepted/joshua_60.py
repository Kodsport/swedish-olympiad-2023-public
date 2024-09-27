#!/usr/bin/env python3
# Should get 60

n,m,k=[int(i) for i in input().split()]



def recur(n_roll, msum, target,memo):
    if n_roll==n:
        return msum==target
    
    if (n_roll,msum) in memo:
        return memo[(n_roll,msum)]
    
    ret = 0
    for i in range(1,m+1):
        ret += recur(n_roll+1,msum+i,target,memo)

    memo[(n_roll,msum)] = ret
    return ret


freq = [0] * (n*m+1)

for i in range(n*m+1):
    memo = {}
    freq[i] = recur(0,0,i,memo)

s = sum(freq)
freq = [i/float(s) for i in freq]
freq = sorted(freq, reverse=True)
ans = 0
for i in range(k):
    ans += freq[i]
print(f'{ans:.15f}')
