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
    n = inp()
    s = instr()
    l, r = 0, n//2 -1
    while l < r:
        if s[l] == s[n-1-l]:
            l += 1
        else:
            break
    
    while r > l:
        if s[r] == s[n-1-r]:
            r -= 1
        else:
            break

    if (l == r):
        print("Yes")
    else:
        chk = True
        for i in range(l, r+1):
            if s[i] == s[n-1-i]:
                chk = False
        if chk:
            print("Yes")
        else:
            print("No")
    
        