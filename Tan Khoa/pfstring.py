# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())
arr = input()

cnt = dict()

res = 0

for v in arr:
    if v not in cnt:
        cnt[v] = 1
    else:
        res += cnt[v]
        cnt[v] += 1
print(res)
