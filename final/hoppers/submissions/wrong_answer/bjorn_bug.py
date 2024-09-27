#!/usr/bin/env python3

import sys
input = sys.stdin.readline

"""
Read input
"""

n,m,N = [int(x) for x in input().split()]
mat = ''.join(input().rstrip() for _ in range(n))

locations = []
for _ in range(N):
    r,c = [int(x) for x in input().split()]
    locations.append(r * m + c)

"""
Create a list of list for the reversed graph
"""
graph = [[] for _ in range(n * m)]
for ind in range(n * m):
    c = mat[ind]
    if c == '<':
        ind2 = ind - 1
    elif c == '>':
        ind2 = ind + 1
    elif c == 'v':
        ind2 = ind + m
    elif c == '^':
        ind2 = ind - m
    graph[ind2].append(ind)


"""
Detect all cycles
"""

def find_SCC(graph):
    SCC, S, P = [], [], []
    depth = [0] * len(graph)
 
    stack = list(range(len(graph)))
    while stack:
        node = stack.pop()
        if node < 0:
            d = depth[~node] - 1
            if P[-1] > d:
                SCC.append(S[d:])
                del S[d:], P[-1]
                for node in SCC[-1]:
                    depth[node] = -1
        elif depth[node] > 0:
            while P[-1] > depth[node]:
                P.pop()
        elif depth[node] == 0:
            S.append(node)
            P.append(len(S))
            depth[node] = len(S)
            stack.append(~node)
            stack += graph[node]
    return SCC[::-1]

# Find cycles (SCC of size > 1)
SCC = find_SCC(graph)
cycles = [scc for scc in SCC if len(scc) > 1]

# Disconnect the cycles
for cycle in cycles:
    for i in range(len(cycle)):
        node1 = cycle[i]
        node2 = cycle[i - 1]
        graph[node2].remove(node1) 



"""
Precompute a bfs and dist from the cycle nodes
"""

dist = [0] * (n * m) # Distance to clostest cycle node
bfs = [node for cycle in cycles for node in cycle]

for node in bfs:
    for child in graph[node]:
        dist[child] = dist[node] + 1
        bfs.append(child)


"""
Simulate process of items traveling towards the cylce, and record any crashes that happens outside of the cycles
Time complexity: O(n * m + (N log N))

The idea is to simulate the items going through the hoppers.
This is done by merging dictionaries using small to large merging.
If 2 or multiple items collide, then record the collision and and remove items from the dictionary
"""

# Store a dictionary at every node
data = [{} for _ in range(n * m)]
for item in locations:
    data[item][dist[item]] = item

new_crashes = []
crashes = {}
def merge(dict1, dict2):
    # Merge using small to large merging
    if len(dict2) > len(dict1):
        dict1, dict2 = dict2, dict1

    for d in dict2:
        item = dict2[d]
        if d in dict1: # Crash detected
            new_crashes.append(item)
            # Note that the item dict1[d]
            # technically also is part of the crash
            # But that is taken care of later.

            # The reason why dict1[d] is left as it is, is
            # to dect crashes with more than 2 items
        else: # No crash occured
            dict1[d] = item
    return dict1

for node in bfs[::-1]:
    new_crashes.clear()
    
    for child in graph[node]:
        data[node] = merge(data[node], data[child])
    
    # Record all crashes that occurd at node
    dictionary = data[node]
    for item in new_crashes:
        crashes[item] = node

        # Take care of the crashes that wasn't taken care of before
        d = dist[item]
        if d in dictionary:
            item = dictionary[d]
            del dictionary[d]
            crashes[item] = node

"""
Simulate process of items going cylce, and record any crashes that happens outside of the cycles
Time complexity: O(n * m + (N log N))

This is done by grouping items that collide at 'infinity' in the same list. 
Then sorting that list depending on when the item enters the cycle.
Finally simulate all crashes.
"""

for cycle in cycles:
    C = len(cycle)
    items = [[] for _ in range(C)] # list of lists of items that collide at 'infinity'
    
    for i in range(C):
        node = cycle[i]

        # Case 1: item started out in the cycle
        dictionary = data[node]
        for d in dictionary:
            item = dictionary[d]
            items[(i + d) % C].append(item)

        # Case 2: items that didn't start out in the cycle
        for child in graph[node]:
            dictionary = data[child]
            for d in dictionary:
                item = dictionary[d]
                items[(i + d) % C].append(item)
    
    items = [sorted(I, key = dist.__getitem__, reverse = True) for I in items] # Sort items by time they enter the cycle

    for i in range(C):
        I = items[i]
        while len(I) > 1: # 2 or more items occupy the same position in the cycle, so there will be at least one crash
            t = dist[I[-2]] # Time when crash occurs
            node = cycle[(i - t) % C] # Node where crash occurs

            # Find all items part of the crash
            while I and dist[I[-1]] <= t:
                item = I.pop()
                crashes[item] = node


for item in locations:
    if item not in crashes:
        print('cycle')
    else:
        node = crashes[item]
        r,c = divmod(node, m)
        print('%d %d' % (r,c))