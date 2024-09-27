#!/usr/bin/env python3
import sys
import string
from itertools import combinations

tokens=sys.stdin.read().split()
N=int(tokens[0])

level=[]
con=dict([(s,[]) for s in string.ascii_uppercase])
for i in range(N):
	level.append(int(tokens[i*2+1]))
	for s in tokens[i*2+2]: con[s].append(i)

INF=1000000
d=[[INF] * N for _ in range(N)]
for i in range(N): d[i][i]=0
for s in con:
	for (i,j) in combinations(con[s],2):
		d[i][j]=d[j][i]=abs(level[i]-level[j])

for k in range(N):
	for i in range(N):
		for j in range(N):
			if d[i][k]+d[k][j]<d[i][j]:
				d[i][j] = d[i][k]+d[k][j]

dist=[d[i][i+1] for i in range(N-1)]
#print(dist)
print(sum(dist))
