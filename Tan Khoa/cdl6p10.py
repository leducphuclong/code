# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
arr = list(map(int, input().split()))
n = len(arr)

cnt = 0
for i in range(1, n-1):
    if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
        cnt += 1
print(cnt)
