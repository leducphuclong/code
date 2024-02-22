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
    
    a.insert(0, 0)
    
    pre = 1
    
    while pre < n and a[pre] <= a[pre+1]:
        pre += 1
    
    suf = 1
    
    while suf < n and a[n-suf+1] <= a[n-suf]:
        suf += 1

    if suf + pre >= n:
        print("YES")
    else:
        print("NO")

    