#!/usr/bin/env python3
def get():
    n = int(input())
    inp = ["" for i in range(n)]

    for i in range(3):
        l = list(input().split(" "))
        for j in range(n):
            inp[j] += l[j] + '$'

    return inp


def combine(a,b,c):
    return a + '$' + b + '$' + c + '$'

l1 = ".."
l2 = "*."
l3 = ".*"
l4 = "**"
m = dict()
rev_m = dict()
m["0"] = combine(l3,l4,l1)
m["1"] = combine(l2,l1,l1)
m["2"] = combine(l2,l2,l1)
m["3"] = combine(l4,l1,l1)
m["4"] = combine(l4,l3,l1)
m["5"] = combine(l2,l3,l1)
m["6"] = combine(l4,l2,l1)
m["7"] = combine(l4,l4,l1)
m["8"] = combine(l2,l4,l1)
m["9"] = combine(l3,l2,l1)

for ky,val in m.items():
    rev_m[val] = ky


# Solve
a = [rev_m[el] for el in get()]
b = [rev_m[el] for el in get()]

a = int("".join(a))
b = int("".join(b))

res = list(str(a+b))
res = [list(m[el].split("$")) for el in res]
print(" ".join([el[0] for el in res]))
print(" ".join([el[1] for el in res]))
print(" ".join([el[2] for el in res]))
