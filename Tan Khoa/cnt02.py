# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())
arr = list(map(int, input().split()))

arr.sort()

cnt = 1
for i in range(1, n):
    if arr[i-1] == arr[i]:
        cnt += 1
    else:
        print(arr[i-1], cnt)
        cnt = 1
print(arr[-1], cnt)
