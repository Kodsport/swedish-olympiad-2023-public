#!/usr/bin/python3

n, t = map(int, input().split())
no = n+1
for i in range(1, n+1):
    print("?",i, flush=True)
    X = list(map(int, input().split()))
    if X[0] != 0:
        no = i

X = []
for i in range(1, n+2):
    if i != no:
        X.append(i)

print("!", *X, flush=True)
