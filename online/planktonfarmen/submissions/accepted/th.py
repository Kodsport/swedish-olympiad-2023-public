#! /usr/bin/env python3
A, N = int(input()), int(input())
pairs = list(sorted(map(int, input().split())))

i = cages = 0
while i < N - cages - 1:
    cages += int(pairs[i] * pairs[-cages - 1] >= A)
    i += 1
print(cages)
