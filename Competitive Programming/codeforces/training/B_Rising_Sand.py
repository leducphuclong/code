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
    n, k = invr()
    a = inlt()
    a.insert(0, 0)
    
    if k == 1:
        print(ceil((n-2)/2))
    else:
        ans = 0
        for i in range(2, n):
            if a[i] > a[i-1] + a[i+1]:
                ans += 1
        print(ans)