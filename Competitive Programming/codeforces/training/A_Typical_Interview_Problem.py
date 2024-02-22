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
norm = "FBFFBFFBFBFFBFFBFBFFBFFB"
# Main function
for _ in range(inp()):
    n = inp()
    s = input().strip()
    if norm.find(s) != -1:
        print("YES")
    else:
        print("NO")