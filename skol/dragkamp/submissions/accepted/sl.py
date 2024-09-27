#!/usr/bin/env python3
s1, s2, s3, s4 = map(int, input().split())

def ran(s):
    return [i for i in range(max(-5, -s), min(5, s) + 1) if i % 2 == s % 2]

for n1 in ran(s1):
    for n2 in ran(s2):
        for n3 in ran(s3):
            for n4 in ran(s4):
                if n1 * 1 + n2 * 2 + n3 * 3 + n4 * 4 == 0 and n1 + n2 + n3 + n4 == 0:
                    print(
                        (s1 - abs(n1)) // 2 + max(n1, 0),
                        (s2 - abs(n2)) // 2 + max(n2, 0),
                        (s3 - abs(n3)) // 2 + max(n3, 0),
                        (s4 - abs(n4)) // 2 + max(n4, 0),
                    )
                    exit()
print("nej")
