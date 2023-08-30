# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())
arr = list(map(int, input().split()))

MOD = int(1e9+7)

s = 0
r = 0
for v in arr:
    r += v*s
    r %= MOD    
    s += v

print(r)
