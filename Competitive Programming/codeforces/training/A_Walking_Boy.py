# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
from collections import defaultdict

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
# Precompute
    
# Main function
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    n = int(input())
    arr = inlt()
    cnt = 0
    arr.insert(0, 0)
    for i in range(1, n+1):
        cnt += (arr[i]-arr[i-1]) // 120
    cnt += (1440-arr[-1]) // 120
    if cnt >= 2:
        print("YES")
    else:
        print("NO")