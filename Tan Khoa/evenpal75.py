# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())

for _ in range(n):
    s = input()
    l = len(s)
    ans = "NO"
    for i in range(1, l):
        if s[i] == s[i-1]:
            ans = "YES"
    print(ans)
