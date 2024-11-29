import sys

def input():
    return sys.stdin.buffer.readline().strip()

MOD = 998244353
ma = int(1e6 + 5)
P = [1] * ma
D = [[] for _ in range(ma)]
for i in range(2, ma):
    if P[i] == 1:
        for j in range(i, ma, i):
            P[j] = i
F = [0] * ma
LU = [0] * ma
BMS = [[] for _ in range(ma)]
RES = []
from itertools import combinations
def getBMS(x):
    if not BMS[x]:
        y = help(x)
        for i in range(len(y)):
            p = combinations(y, i + 1)
            for a in p:
                xx = 1
                for j in a:
                    xx *= j
                BMS[x].append((xx,i))
    return BMS[x]
def helps(x):
    y = x
    while x != 1:
        s = P[x]
        D[y].append(s)
        while x % s == 0:
            x //= s


def help(x):
    if not D[x]: helps(x)
    return D[x]




for yy in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    for xx,i in getBMS(A[0]):
        F[xx] = 1
        LU[xx] = yy
    for i in range(1, n - 1):
        tot = 0
        for xx, j in getBMS(A[i]):
            if LU[xx] != - 1 and LU[xx] != yy:
                F[xx] = 0
            LU[xx] = yy
            if F[xx]:
                if j % 2:
                    tot -= F[xx]
                    tot %= MOD
                else:
                    tot += F[xx]
                    tot %= MOD
        for xx, j in getBMS(A[i]):
            F[xx] += tot
            F[xx] %= MOD
    S = 0
    for xx,i in getBMS(A[-1]):
        if LU[xx] != - 1 and LU[xx] != yy:
            LU[xx] = yy
            F[xx] = 0
        if F[xx]:
            if i % 2:
                S -= F[xx]
                S %= MOD
            else:
                S += F[xx]
                S %= MOD

    RES.append(str(S))
print("\n".join(RES))