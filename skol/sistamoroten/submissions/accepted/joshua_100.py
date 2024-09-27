#!/usr/bin/env python3
# Should get 100

n,m,k=[int(i) for i in input().split()]


dp = [0] * (n*m+1)
dp[0] = 1
newdp = [0] * (n*m+1)
ops=0
for j in range(n):
    pf = [0] * (n*m+1)
    pf[0] = dp[0]
    for i in range(1, len(dp)): pf[i]=pf[i-1]+dp[i]


    for i in range(len(dp)):
        ops+=1
        pf_hi = 0
        if i > 0: pf_hi = pf[i-1]
        pf_lo = 0
        if i-m-1>=0: pf_lo = pf[max(0, i-m-1)]

        newdp[i] = (pf_hi-pf_lo)/m
    dp = newdp
    newdp = [0] * (n*m+1)

dp = sorted(dp, reverse=True)
ans = 0
for i in range(k):
    ans += dp[i]
print(f'{ans:.15f}')
