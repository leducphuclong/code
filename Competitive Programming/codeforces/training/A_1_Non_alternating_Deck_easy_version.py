# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
from collections import defaultdict
from math import floor, ceil

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
    
# Main function
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    n = inp()
    s, pos, t1, t2, b1, w2 = 0, 0, 0, 0
    for i in range(1, n+1):
        if s+i > n:
            remain = n-s
            if (i//2) % 2 == 0:
                t1 += remain; b1 += remain // 2
            else:
                t2 += remain; w2 += remain // 2
            break
        else:
            if (i // 2) % 2 == 0:
                t1 += i; b1 += i // 2
            else:
                t2 += i; w2 += i // 2
            s += i

    print(t1-b1, b1, w2, t2-w2)
    
    
    