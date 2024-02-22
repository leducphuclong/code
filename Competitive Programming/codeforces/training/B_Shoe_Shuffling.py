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
    
    p = [0]
    for i in range(n):
        p.append(i+1)

    last = defaultdict(int)     
    cnt = defaultdict(int)   
    
    for i in range(1, n+1):
        if last[a[i]] != 0:
            l = last[a[i]]
            
            tmp = p[i]
            p[i] = p[l]
            p[l] = tmp
            
        cnt[a[i]] += 1
        last[a[i]] = i
    
    yes = True
    for i in range(1, n+1):
        if cnt[a[i]] == 1:
            yes = False
    
    if yes:
        p.pop(0)
        print(*p)
    else:
        print(-1)
    