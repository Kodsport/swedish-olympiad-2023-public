#!/usr/bin/env python3
def query(y):
    print("? {}".format(y), flush=True)
    return [int(x) for x in input().split()]

def make_map(V):
    res = {}
    for v in V:
        if v not in res:
            res[v] = 0
        res[v] += 1
    return res

def map_count(M, x):
    if x not in M: return 0
    return M[x]

def inc(M, x):
    if x not in M: M[x] = 0
    M[x] += 1

def dec(M, x):
    if x not in M: M[x] = 0
    M[x] -= 1

def odd_one_out(M1, M2):
    for x, f in M1.items():
        if f == 0: continue
        if x not in M2 or M2[x] < f:
            return x
    return -1

n, T = map(int, input().split())
Q1 = query(1)
last = 1
for c1 in range(n):
    last += Q1[c1]

ans = []
if n > 1:
    M1 = make_map(Q1)
    if Q1[0] == 0:
        ans.append(1)
    else:
        Q2 = query(2)
        M2 = make_map(Q2)
        x = odd_one_out(M1, M2)
        ans.append(x + 1)

    for c1 in range(1, n-1):
        V = query(ans[-1] + 1)
        M2 = make_map(V)

        if c1 == 1:
            dec(M1, ans[0] -1)
            inc(M1, 1)
        else:
            dec(M1, ans[c1-1] - ans[c1-2] - 1)
            inc(M1, ans[c1-1] - ans[c1-2])

        x = odd_one_out(M1, M2)
        ans.append(ans[-1] + x)
        M1 = dict(M2)

ans.append(last)
print("!", *ans, flush=True)
