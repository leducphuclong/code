# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())
arr = list(map(int, input().split()))

sav = dict()

cnt = 0
for v in arr:
    if v-1 not in sav:
        cnt += 1
    sav[v] = 1

print(cnt)
