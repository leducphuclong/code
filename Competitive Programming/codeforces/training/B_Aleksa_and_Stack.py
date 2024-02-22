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
    n = inp()
    for i in range(1, n+1):
        print(2*i-1, end = ' ')
    print()