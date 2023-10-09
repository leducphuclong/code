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
def sum_of_sequence(l, r, s):
    return (r+l)*((r-l)//s+1)//2
# Precompute

# IO
input = sys.stdin.readline
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function
for _ in range(inp()):
    n, k, x = invr()
    mn = sum_of_sequence(1, k, 1)
    mx = sum_of_sequence(n-k+1, n, 1)
    if mn <= x and x <= mx:
        print("YES")
    else:
        print("NO") 
    