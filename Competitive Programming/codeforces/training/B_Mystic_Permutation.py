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
    
    if (n == 1):
        print(-1)
        continue
    
    b = []
    for i in range(n):
        b.append(i+1)
    
    for i in range(n-1):
        if a[i] == b[i]:
            tmp  = b[i]
            b[i] = b[i+1]
            b[i+1] = tmp
    
    if a[-1] == b[-1]:
        tmp = b[-1]
        b[-1] = b[-2]
        b[-2] = tmp
    
    print(*b)
    