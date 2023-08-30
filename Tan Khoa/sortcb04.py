# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n, m = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()

dame = 0

for i in range(min(m, n)):
    if arr[i] < 0:
        dame += arr[i]

print(abs(dame))
