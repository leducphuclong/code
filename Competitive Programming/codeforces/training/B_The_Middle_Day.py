# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
from collections import defaultdict

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
m = sum(arr)//2+1
s = 0
a, b = -1, -1
for i in range(n):
    if s + arr[i] < m:
        s += arr[i]
    else:
        a = i+1
        b = m-s
        break
print(a, b)