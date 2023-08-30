# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = input()

cnt = dict()

for v in n:
    if v not in cnt:
        cnt[v] = 1
    else:
        cnt[v] += 1

l = 0
for value in cnt.values:
    if value % 2 == 1:
        l += 1

