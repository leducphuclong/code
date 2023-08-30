# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
arr = list(map(int, input().split()))
n = len(arr)

for i in range(n):
    if arr[i] > 0:
        arr[i] = 1
    elif arr[i] < 0:
        arr[i] = -1
    else:
        arr[i] = 0

print(*arr)
