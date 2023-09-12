# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
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
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    n, m = invr()
    s1 = instr()
    s2 = instr()
    s2.reverse()
    s1.extend(s2)
    
    cnt = 0
    for i in range(n+m-1):
        if s1[i] == s1[i+1]:
            cnt += 1
    if (cnt > 1):
        print("NO")
    else:
        print("YES")