# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())
arr = list(map(int, input().split()))
s = sum(arr)/2

dp = []*(n+1)

