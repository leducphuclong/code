# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort()

res = a[n-m]
for i in range(n-m):
    if (a[i] != b[i]):
        res = a[i]
        break
print(res)

if (m == 2):
    a.reverse()
    b.reverse()
    print(a)
    print(b)
    # res = a[n-m]
    for i in range(n-m):
        if a[i] != b[i]:
            res = a[i]
            break
    print(res)
