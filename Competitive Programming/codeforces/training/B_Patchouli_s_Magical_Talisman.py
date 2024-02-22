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
    
    Nodd = 0
    
    for v in a:
        if v & 1:
            Nodd += 1
    
    if Nodd == n:
        print(0)
        continue

    if Nodd == 0:
        m = 9999999999999
        for v in a:
            cnt = 0
            while v % 2 == 0:
                v //= 2
                cnt += 1
            m = min(m, cnt)
        # print("m: ", m)
        print(m+n-1)
    else:
        print(n-Nodd)
            
        
            
        