# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

for v in range(0, n-1, 2):
    if arr[v] != arr[v+1]:
        print(arr[v])
        break
