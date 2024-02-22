# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
from collections import defaultdict
from math import ceil, sqrt, gcd

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
    l, r = invr()
    if r <= 3:
        print(-1)
    else:
        a, b = -1, -1
        for i in range(2, int(sqrt(l) + 1)):
            if l % i == 0:
                a, b = i, l-i
                break
        if (a == -1):
            print(-1)
        else:
            print(a, b)
        a = 2
        b = ceil(max(3, l)/2-1)*2
        print(a, b)
        
    
    