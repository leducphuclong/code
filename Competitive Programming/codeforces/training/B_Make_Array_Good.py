# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
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
    pr = []
    for i in range(n):
        pr.append([a[i], i+1])
    
    pr.sort()
    ans = []
    for i in range(1, n):
        tmp = ceil(pr[i][0]/pr[i-1][0])*pr[i-1][0]
        ans.append([pr[i][1], tmp-pr[i][0]])
        pr[i][0] = tmp
    
    print(len(ans))
    for v in ans:
        print(v[0], v[1])
    
    
    
        