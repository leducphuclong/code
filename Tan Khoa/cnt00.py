# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n, x = map(int, input().split())
arr = list(map(int, input().split()))

cnt = 0

for v in arr:
    if (x == v):
        cnt += 1

print(cnt)
