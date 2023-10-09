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

    cnt = defaultdict(int)
    last = defaultdict(int)
    
    for i in range(1, n+1):
        col = a[i-1]
        dst = i - last[col] -1
        
        if dst & 1 == 0:
        #     cnt[col] = 1
        # else:
            cnt[col] += 1
            last[col] = i
        elif last[col] == 0:
            cnt[col] = 1
            
        # print("i: ", i)
        # print("col 3: ", cnt[3])
        # print("last 3: ", last[3])
            

    
    for i in range(1, n+1):
        print(cnt[i], end = ' ')
    print()