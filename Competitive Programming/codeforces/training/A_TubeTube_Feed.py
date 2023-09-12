# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
from collections import defaultdict

############ ---- Input Functions ---- ############
def inp():
    return int(input())

def inlt():
    return list(map(int, input().split()))

def insr():
    return list(input().strip())

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
# Precompute
    
# Main function
for _ in range(inp()):
    n, t = invr()
    a = inlt()
    b = inlt()
    
    for i in range(n):
        a[i] += i

    idx, ent = -1, 0
    
    for i in range(n):
        if a[i] <= t and b[i] > ent:
            ent = b[i]
            idx = i+1
    
    print(idx)