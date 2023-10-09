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
    if (n == 1):
        print(0)
        continue
    
    sta = 0
    while sta < n and s[sta] == '0':
        sta += 1

    cnt = 0
    for i in range(sta, n):
        if (int(s[i]) + cnt) & 1 == 0:
            cnt += 1
    
    print(cnt)
        