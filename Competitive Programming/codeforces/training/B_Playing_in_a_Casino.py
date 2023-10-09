# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
from collections import defaultdict
from math import *

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

# IO
input = sys.stdin.readline
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function
for _ in range(inp()):
    n, m = invr()
    arr = []
    for i in range(n):
        arr.append(inlt())
    
    col = [[] for _ in range(m)]
    for i in range(n):
        for j in range(m):
            col[j].append(arr[i][j])

    pfs = [[0] for _ in range(m)]
    
    for i in range(m):
        col[i].sort()
        for v in col[i]:
            pfs[i].append(pfs[i][-1]+v)
    ans = 0
    for i in range(n):
        for j in range(m):
            ans += col[j][i]*i - pfs[j][i]
    
    print(ans)