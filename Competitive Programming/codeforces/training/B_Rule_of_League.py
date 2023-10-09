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
    n, x, y = invr()
    if x == 0 and y == 0:
        print(-1)
        continue
    if x != 0 and y != 0:
        print(-1)
        continue
    w = max(x, y)
    if (n-1) % w == 0:
        # print((n-1) // w)
        for i in range((n-1) // w):
            for j in range(w):
                print(w*i+2, end = ' ')
        print()
    else:
        print(-1)
                