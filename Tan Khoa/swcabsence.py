# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n, m = map(int, input().split())
arr = list(map(int, input().split()))

save = dict()
for v in arr:
    save[v] = 1

for i in range(1, n+1):
    if i not in save:
        print(i, end=' ')
