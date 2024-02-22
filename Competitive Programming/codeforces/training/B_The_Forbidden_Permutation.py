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

# Main function
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    n, m, d = invr()
    p = inlt()
    a = inlt()
    
    pos = [0]*(n+1)
    for i in range(n):
        pos[p[i]] = i+1
    
    ans = 99999999999
    for i in range(m-1):
        if (pos[a[i]] >= pos[a[i+1]] or pos[a[i+1]] > pos[a[i]]+d):
            ans = 0
            break
        
        x, y = a[i], a[i+1]
        
        ans = min(ans, pos[y]-pos[x])
        
        d1 = pos[x] + d - pos[y] + 1
        
        if (pos[x]-1 + n-pos[y] >= d1):
            ans = min(ans, d1)
        
        
    print(ans)
        
        
        
        
            
        