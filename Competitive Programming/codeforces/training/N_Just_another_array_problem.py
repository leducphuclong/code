# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
from collections import defaultdict
from bisect import bisect_left

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
n = inp()
arr = inlt()
l, r = defaultdict(lambda: -1), defaultdict(lambda: -1)
for i in range(n):
    if l[arr[i]] == -1:
        l[arr[i]] = i
    r[arr[i]] = i 

q = inp()
sft = 0
for _ in range(q):
    x, y = input().strip().split()
    y = int(y)
    if x == 's':
        sft += y
    else:
        if r[y] == -1:
            print(-1)
        else:
            left = (l[y]+sft%n+n)%n
            right = (r[y]+sft%n+n)%n
            if left <= right:
                print(left+1)
            else:
                print(1)