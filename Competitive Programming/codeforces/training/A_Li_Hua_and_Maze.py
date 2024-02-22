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

def instr():
    return list(input().strip())

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
def f(x, y, n , m):
    if (x == 1 and y == 1) or (x == n and y == 1) or (x == n and y == m) or (x == 1 and y == m):
        return 2
    if (x == 1 or x == n or y == 1 or y == m):
        return 3
    return 4

# Precompute
    
# Main function
for _ in range(inp()):
    n, m = invr()
    x, y, z, t = invr()
    print(min(f(x, y, n, m), f(z, t, n, m)))