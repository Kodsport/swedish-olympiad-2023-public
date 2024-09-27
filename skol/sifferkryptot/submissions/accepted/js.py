#!/usr/bin/env python3
S = input()

sol = [0] * (len(S) + 1)
sol[0] = 1
for i in range(len(S)):
    sol[i + 1] = sol[i] if S[i] != '0' else 0
    if i and S[i - 1] in '12': sol[i + 1] += sol[i - 1]
print(sol[-1])
