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
    n, k, b, s = invr()
    
    sol = True
    
    ans = []
    ans.append(b*k)
    
    s -= ans[-1]
    if s < 0:
        sol = False
    else:
        ans[-1] += min(k-1, s)
        s -= min(k-1, s)
    
    for i in range(n-1):
        if s >= k-1:
            ans.append(k-1)
            s -= k-1
        else:
            ans.append(s)
            s = 0
    
    if s > 0:
        sol = False
    
    if sol == False:
        print(-1)
    else:
        print(*ans)
    