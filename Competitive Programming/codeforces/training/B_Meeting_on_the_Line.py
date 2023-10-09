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
    n = inp()
    a = inlt()
    b = inlt()
    mn, mx = 9999999999999, -999999999999
    for i in range(n):
        mn = min(mn, a[i]-b[i])
        mx = max(mx, a[i]+b[i])
    # print("max: ", max(dist), " min: ", min(dist))
    print(format((mx+mn)/2, "0.6f"))
    