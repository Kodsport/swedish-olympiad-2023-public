#!/usr/bin/python3

big = 10**9+7
MAXN = 401
MAXA = 401
DP = [-big] * (MAXN*MAXA)
sumd = 0
result = ["lose", "draw", "win"]

n = int(input())
DP[0] = 0
for _ in range(n):
    a, d = map(int, input().split())
    sumd += d
    for suma2 in range(0, MAXA*MAXN-a):
        suma = MAXA*MAXN-suma2-1
        DP[suma] = max(DP[suma], DP[suma-a] + a-d)
for suma in reversed(range(0, MAXN*MAXA-1)):
    DP[suma] = max(DP[suma], DP[suma+1])

q = int(input())
ANS = [0, 0, 0]
for _ in range(q):
    inp = input().split()
    a = int(inp[0])
    d = int(inp[1])
    ans = 0
    if sumd >= a:
        ans = 1
    if DP[d+1] >= a+d-sumd:
        ans = 1
    if DP[d+1] > a+d-sumd:
        ans = 2
    ANS[2-ans] += 1
    
print(*ANS)
