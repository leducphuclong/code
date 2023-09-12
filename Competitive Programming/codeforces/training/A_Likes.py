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
# Precompute
    
# Main function
for _ in range(inp()):
    n = inp()
    arr = inlt()
    like, unlike = 0, 0
    for v in arr:
        if v > 0:
            like += 1
        else:
            unlike += 1
    # Print max array
    for i in range(like):
        print(i+1, end = ' ')
    for i in range(unlike):
        print(max(0, like-i-1), end = ' ')
    print()
    # Print min array
    for __ in range(unlike):
        print(1, 0, end = ' ')
    for i in range(like-unlike):
        print(i+1, end = ' ')
    print()
    