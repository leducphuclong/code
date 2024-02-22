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
input = sys.stdin.readline
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function
for _ in range(inp()):
    n = instr()
    s1, s2 = 0, 0
    n1, n2 = "", ""
    for c in n:
        add = int(c)
        if int(c) & 1:
            if s1 < s2:
                n1 += str(add//2+1)
                s1 += add//2+1
                n2 += str(add//2)
                s2 += add//2
            else:
                n2 += str(add//2+1)
                s2 += add//2+1
                n1 += str(add//2)
                s1 += add//2
        else:
            n1 += str(add//2)
            n2 += str(add//2)
            s1 += add//2
            s2 += add//2
    print(int(n1), int(n2))