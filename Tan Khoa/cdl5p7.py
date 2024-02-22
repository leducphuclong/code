# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
q = int(input())

for _ in range(q):
    s = input()
    ss1 = input()
    ss2 = input()
    s = s.replace(ss1, ss2)
    print(s)
