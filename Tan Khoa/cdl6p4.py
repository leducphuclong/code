# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n, m = map(int, input().split())
c1 = list(map(str, input().split()))
c2 = list(map(str, input().split()))

c3 = c1 + c2

c3.sort()

print(*c3)
