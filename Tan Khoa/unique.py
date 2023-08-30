# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

for v in range(n-1):
    if arr[v] != arr[v+1]:
        if arr[v+1] == arr[v+2]:
            print(arr[v])
        else:
            print(arr[v+1])
        break
