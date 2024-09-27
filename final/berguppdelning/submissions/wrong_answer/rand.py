#!/usr/bin/env python3
import random
t = int(input())
r,c,n = map(int,input().split())
for _ in range(r):
    row = [random.randrange(0, n) for j in range(c)]
    print(*row)

