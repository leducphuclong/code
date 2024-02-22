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
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function
for _ in range(inp()):
    n = inp()
    a = inlt()
    a.insert(0, 1)
    a.append(1)
    
    b = [0]*(n+2)
    for i in range(1, n+2):
        b[i] = lcm(a[i], a[i-1])
        
    chk = True
    for i in range(1, n+1):
        if gcd(b[i], b[i+1]) != a[i]:
            chk = False
    if chk:
        print("YES")
    else:
        print("NO")
            