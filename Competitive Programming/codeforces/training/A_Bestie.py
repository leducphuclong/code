# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
from collections import defaultdict
from math import gcd

############ ---- Input Functions ---- ############
def inp():
    return int(input())

def inlt():
    return list(map(int, input().split()))

def instr():
    return list(input().strip())

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
def gcd_array(arr):
    ans = arr[0]
    for v in arr:
        ans = gcd(ans, v)
    return ans
# Precompute
    
# Main function
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    n = inp()
    arr = inlt()
    
    a1, a2 = [], []
    for v in arr:
        a1.append(v)
        a2.append(v)
    
    ans1, ans2 = 0, 0
    
    for i in range(n-2, n):
        if gcd_array(a1) > 1:
            a1[i] = gcd(i+1, a1[i])
            ans1 += n-i
    
    for i in range(n-1, n-3, -1):
        if gcd_array(a2) > 1:
            a2[i] = gcd(i+1, a2[i])
            ans2 += n-i
    
    print(min(ans1, ans2))
        