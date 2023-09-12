# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
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
def distance(a, b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    # Input
    n, k, a, b = invr()
    loc = []
    for v in range(n):
        x, y = invr()
        loc.append([x, y])
    # Solve
    ca, cb = 10000000000, 10000000000
    for i in range(k):
        ca = min(ca, distance(loc[a-1], loc[i]))
        cb = min(cb, distance(loc[b-1], loc[i]))
    print(min(distance(loc[a-1], loc[b-1]), ca+cb))
    
    
    
    
     
    
    