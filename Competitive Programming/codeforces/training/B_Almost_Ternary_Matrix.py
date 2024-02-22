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
sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')
# Main function
for _ in range(inp()):
    n, m = invr()
    for i in range(1, n+1):
        for j in range(1, m+1):
            print(int((i % 4 <= 1) == (j % 4 <= 1)), end = ' ')
        print()