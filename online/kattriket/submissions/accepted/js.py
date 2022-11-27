#!/usr/bin/env python3
import sys
import heapq
import sys

sys.setrecursionlimit(300000)

N = int(input())

def make_tree():
    G = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = map(int, input().split())
        G[a].append(b)
        G[b].append(a)

    children = [[] for _ in range(N)]
    depth = [-1] * N
    furthest = [-1] * N
    furthestidx = [-1] * N

    def dfs(at, par, d):
        depth[at] = d
        f, fidx = -1, -1
        for adj in G[at]:
            if adj == par: continue
            children[at].append(adj)
            nf = 1 + dfs(adj, at, d + 1)
            if nf > f:
                f = nf
                fidx = adj
        furthest[at] = f
        furthestidx[at] = fidx
        return f

    dfs(0, -1, 0)

    return children, furthest, furthestidx

ch, furthest, furthestidx = make_tree()

top = []
for immediate in ch[0]:
    top.append((-furthest[immediate], immediate))
heapq.heapify(top)

answers = []
leafs = 0
while top:
    _, nx = heapq.heappop(top)
    leafs += 1
    while nx != -1:
        answers.append(leafs)
        for adj in ch[nx]:
            if adj != furthestidx[nx]:
                heapq.heappush(top, (-furthest[adj], adj))
        nx = furthestidx[nx]
print(*answers)
