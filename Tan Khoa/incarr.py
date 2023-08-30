# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a = a+b
a = set(a)

print(len(a))
