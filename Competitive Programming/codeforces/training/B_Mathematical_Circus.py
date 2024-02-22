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
    
    if k % 4 == 0:
        print("NO")
    else:
        print("YES")
        if k % 4 == 1 or k % 4 == 3:
            for i in range(1, n+1, 2):
                print(i, i+1)
        else:
            for i in range(1, n+1, 2):
                if (i+1) % 4 == 0:
                    print(i, i+1)
                else:
                    print(i+1, i)
            