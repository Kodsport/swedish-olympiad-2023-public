#!/usr/bin/env python3
# Should get 80

n,m,k=[int(i) for i in input().split()]


dp = [0] * (n*m+1)
dp[0] = 1
newdp = [0] * (n*m+1)

for j in range(n):
    for i in range(len(dp)):
        for l in range(1, m+1):
            if i-l>=0:
                newdp[i] += dp[i - l]
        newdp[i] /= m
    dp = newdp
    newdp = [0] * (n*m+1)


dp = sorted(dp, reverse=True)
ans = 0
for i in range(k):
    ans += dp[i]
print(f'{ans:.15f}')
