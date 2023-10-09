# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
from collections import defaultdict
from math import *
input = sys.stdin.readline
output = sys.stdout.readline


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
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    n = inp()
    s = instr()
    
    ans = 0
    for i in range(n):
        # print("i: ", s[i])
        fr = [0]*(10)
        distinct, max_fre = 0, 0
        for j in range(i, min(i+100, n)):
            fr[int(s[j])] += 1
            if fr[int(s[j])] == 1:
                distinct += 1
            if fr[int(s[j])] == 11:
                break
            max_fre = max(max_fre, fr[int(s[j])])
            if max_fre <= distinct:
                ans += 1

    print(ans)
            