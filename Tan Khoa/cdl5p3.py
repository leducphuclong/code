# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
str = input()

q = int(input())

for _ in range(q):
    l, r = map(int, input().split())
    print(str[l:r])
