# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())
arr = list(map(int, input().split()))

dau_tien, cuoi_cung = -1, -1

# Tim so duong dau tien
for i in range(n):
    if arr[i] > 0:
        dau_tien = i+1
        break


# Tim so duong cuoi cung

for i in range(n-1, -1, -1):
    if arr[i] > 0:
        cuoi_cung = i+1
        break

print(dau_tien, cuoi_cung)
