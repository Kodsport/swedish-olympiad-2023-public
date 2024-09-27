#!/usr/bin/env python3
def solve():
    a, b, c, d = map(int, input().split())

    if (a+b+c+d)%2 == 0 and (a+2*b+3*c+4*d)%2 == 0:
        cnt = (a + b + c + d) // 2
        targ = (a + 2*b + 3*c + 4*d) // 2

        for aa in range(max(a//2-1,0),min(a//2+2, a+1)):
            for bb in range(max(b//2-1,0),min(b//2+2, b+1)):
                for cc in range(max(c//2-1,0),min(c//2+2, c+1)):
                    dd = cnt - aa - bb - cc
                    if dd < 0: continue
                    if aa + 2*bb + 3*cc + 4*dd == targ:
                        print(aa, bb, cc, dd)
                        return
    print("nej")

solve()
