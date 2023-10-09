# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
#input = sys.stdin.readline
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
    arr = [[0 for _ in range(n+1)] for __ in range(3)]
    arr[1][1], arr[2][n] = 2*n, 2*n-1   
    for i in range(2, n+1):
        if i & 1:
            arr[1][i], arr[2][i-1] = n+i-2, n+i-1
        else:
            arr[1][i], arr[2][i-1] = i-1, i
    for i in range(1, 3):
        for j in range(1, n+1):
            print(arr[i][j], end = ' ')
        print()
