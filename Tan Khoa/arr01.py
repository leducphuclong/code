# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""

Cách nhập mảng 2 chiều:

n, k = map(int, input().split())

mtx = []
for i in range(n):
    arr = list(map(int, input().split()))
    mtx.append(arr)

for i in range(n):
    for j in range(n):
        print(mtx[i][j], end=' ')
    print()



n = int(input())
arr = list(map(int, input().split()))

pfs = []*(n+1)
for i in range(n+1):
    pfs.append([])
    for j in range(n+1):
        pfs[i].append(0)

chi_so = 0
lon_nhat = 0
for i in range(n):
    if arr[i] > lon_nhat:
        lon_nhat = arr[i]
        chi_so = i

print(lon_nhat)
print(chi_so+1)
