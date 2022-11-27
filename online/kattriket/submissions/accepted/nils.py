#!/usr/bin/env python3

n = int(input())
tree = [[] for _ in range(n)]
for _ in range(n-1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)

bfs = [0]
depth = [-1]*n
depth[0] = 0
for i in range(n):
    u = bfs[i]
    for v in tree[u]:
        if depth[v] == -1:
            depth[v] = depth[u]+1
            bfs.append(v)

deepest = [0] * n
extra = [0] * n
for u in bfs[::-1]:
    deepest[u] = u
    for v in tree[u]:
        if depth[v] > depth[u]:
            if depth[deepest[v]] > depth[deepest[u]]:
                deepest[u] = deepest[v]
    if u != 0:
        extra[deepest[u]] += 1
extra.sort(reverse=True)
ans = []
for i in range(n):
    for _ in range(extra[i]):
        ans.append(i+1)
print(*ans)
    