# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
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
    n = inp()
    a = inlt()
    p = 0
    
    while p < n and a[p] == 0:
        p += 1
    
    z = 0
    for i in range(p, n-1):
        if not a[i]:
            z += 1
    
    ans = sum(a)-a[-1]+z
    
    print(ans)
