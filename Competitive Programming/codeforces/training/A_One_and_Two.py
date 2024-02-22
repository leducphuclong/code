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
    n = inp()
    arr = inlt()
    pfs = [1]
    for v in arr:
        pfs.append(v*pfs[-1])
    loc = n+1
    for i in range(1, n):
        if pfs[i] == pfs[n]//pfs[i] and i < loc:
            loc = i
    if (loc == n+1):
        print(-1)
    else:
        print(loc)