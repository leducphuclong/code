# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
xau1 = input()
xau2 = input()

save1 = dict()

for c in xau1:
    if c not in save1:
        save1[c] = 1
    else:
        save1[c] += 1

res = 0
for c in xau2:
    if c in save1 and save1[c] > 0:
        res += 1
        save1[c] -= 1

print(res)
