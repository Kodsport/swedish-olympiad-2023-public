#!/usr/bin/python3

r, c = map(int, input().split())
k, n = map(int, input().split())

water = set()
for _ in range(k):
    water.add(int(input()))

blocks = []
for _ in range(n):
    y, x = map(int, input().split())
    blocks.append((-y, x))
blocks.sort()

left = {}

for y, x in blocks:
    if (y-1, x) in left:
        left[(y, x)] = x
    elif (y, x-1) in left:
        left[(y, x)] = left[(y, x-1)]
    else:
        left[(y, x)] = x-1
    if x in water and (y-1, x) not in left:
        L = left[(y, x)]
        if (y-1, L) not in left:
            water.add(L)
        if (y-1, x+1) not in left:
            water.add(x+1)
    if x in water:
        water.remove(x)

# Water not allowed to exit grid?
if -1 in water:
    water.remove(-1)
if c in water:
    water.remove(c)
    
print(len(water))
