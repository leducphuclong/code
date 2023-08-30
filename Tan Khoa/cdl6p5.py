# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n, k = map(int, input().split())
mtx = []
for i in range(n):
    mtx.append(list(map(int, input().split())))

pfs = []*(n+1)
for i in range(n+1):
    pfs.append([])
    for j in range(n+1):
        pfs[i].append(0)

for i in range(1, n+1):
    for j in range(1, n+1):
        pfs[i][j] = pfs[i-1][j] + pfs[i][j-1] - pfs[i-1][j-1] + mtx[i-1][j-1]

mav = -999999999999999999
for i in range(n-k, n+1):
    for j in range(n-k, n+1):
        sum_v = pfs[i][j]-pfs[i-k][j] - pfs[i][j-k] + pfs[i-k][j-k]
        if (sum_v > mav):
            mav = sum_v

print(mav)