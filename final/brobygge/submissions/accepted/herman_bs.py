#!/usr/bin/env python3

h, w, t = map(int, input().split())

segments = []

for i in range(t):
    y, x = map(int, input().split())
    segments += [(x, y)]

min_time = 1
max_time = t+1

while min_time != max_time:
    time = (min_time + max_time) // 2

    built = set(segments[:time])
    visited = set()
    queue = []

    for x, y in built:
        if y == 1:
            visited.add((x, y))
            queue += [(x, y)]

    while queue:
        x, y = queue.pop()

        for x2, y2 in [(x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)]:
            if (x2, y2) in built and (x2, y2) not in visited:
                visited.add((x2, y2))
                queue += [(x2, y2)]

    if any(y == h - 2 for x, y in visited):
        max_time = time
    else:
        min_time = time + 1

if min_time==t+1:
    print("nej")
else:
    print(min_time)
