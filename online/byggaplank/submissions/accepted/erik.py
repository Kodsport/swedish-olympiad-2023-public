#!/usr/bin/python3


N, K = map(int, input().split())
h = list(map(int, input().split()))

K = min(K, N - 1)

sort_h = list((h[i], i) for i in range(N))
sort_h.sort()

# h_index_of_sorted maps index in sort_h to index in h

h_index_of_sorted = [-1 for _ in range(N)]
for i in range(N):
    h_index_of_sorted[sort_h[i][1]] = i

# linked list sorted after x-coordinate, with points added in height order
# for time step t, we need to know which element is the t'th smallest,
# and between which element of the linked list it should be added

# linked list = {(left, index in h, right)}
# the left and right neighbors when element is added to linked list is the next adjacent smaller neighbors to the left and right

next_left = [-1 for _ in range(N)]
next_right = [-1 for _ in range(N)]

stack = [-1]
for i in range(N):
    while (len(stack) > 1) and (h[stack[-1]] > h[i]):
        stack.pop()
    next_left[i] = stack[-1]
    stack.append(i)

stack = [N]
for i in range(N - 1, -1, -1):
    while (len(stack) > 1) and (h[stack[-1]] >= h[i]):
        stack.pop()
    next_right[i] = stack[-1]
    stack.append(i)

# precomp done. continue with solve
    
max_area = 0

linked_list = []

for j in range(N):
    i = sort_h[j][1]

    linked_list.append([next_left[i], i, next_right[i]])

    if next_left[i] != -1:
        linked_list[h_index_of_sorted[next_left[i]]][2] = i
    if next_right[i] != N:
        linked_list[h_index_of_sorted[next_right[i]]][0] = i
    
    # go left K steps from i
    # go right K steps from i

    left = []
    right = []

    ptr = i
    ln = 0
    while (ptr != -1) and (ln <= K):
        ptr = linked_list[h_index_of_sorted[ptr]][0]
        left.append(ptr)
        ln += 1
    
    ptr = i
    ln = 0
    while (ptr != N) and (ln <= K):
        ptr = linked_list[h_index_of_sorted[ptr]][2]
        right.append(ptr)
        ln += 1
    
    # now left & right contains the indices of the smaller planks to the left and right
    
    if len(left) + len(right) <= K + 1:
        max_area = max(max_area, h[i] * (right[-1] - left[-1] - 1))

    for l in range(K + 1):
        # it is enough to only consider left[l] and right[K - l]
        if (l < len(left)) and (K - l < len(right)):
            max_area = max(max_area, h[i] * (right[K - l] - left[l] - 1))

print(max_area)
