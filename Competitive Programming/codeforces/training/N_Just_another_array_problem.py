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
def first_index(arr, x):
    index = bisect_left(arr, x)
    if index < len(arr) and arr[index] == x:
        return index
    else:
        return -1
# Precompute
    
# Main function
# sys.stdin = open('in.txt', 'r')
n = inp()
arr = inlt()
q = inp()
sft = 0
for _ in range(q):
    x, y = input().strip().split()
    y = int(y)
    if x == 's':
        sft += y
    else:
        pos = first_index(arr, y)
        if pos == -1:
            print(-1)
        else:
            pos += (sft%n)
            print((pos+n) % n + 1)
            # if pos >= 0:
            #     print(pos%n+1)
            # else:
            #     print(pos+n+1)
    