#!/usr/bin/env python3


n, m, t = map(int, input().split())

segments = []

for i in range(t):
    r, c = map(int, input().split())
    segments += [(r, c)]

def is_possible(time):
    built = set(segments[:time])
    visited = set()
    queue = []

    for r, c in built:
        if r == 1:
            visited.add((r, c))
            queue += [(r, c)]

    while queue:
        r, c = queue.pop()

        for r2, c2 in [(r, c + 1), (r, c - 1), (r + 1, c), (r - 1, c)]:
            if (r2, c2) in built and (r2, c2) not in visited:
                visited.add((r2, c2))
                queue += [(r2, c2)]

    return any(r == n - 2 for r, c in visited)

min_time = 1
max_time = t

if is_possible(max_time):
    while min_time != max_time:
        time = (min_time + max_time) // 2

        if is_possible(time):
            max_time = time
        else:
            min_time = time + 1

    print(min_time)
else:
    print("nej")