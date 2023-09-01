# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())
arr = list(map(int, input().split()))

s = [0]

for i in arr:
    s.append(i+s[-1])

cnt = dict()

kq = 0

for i in s:
    if i not in cnt:
        cnt[i] = 1
    else:
        kq += cnt[i]
        cnt[i] += 1

print(kq)
