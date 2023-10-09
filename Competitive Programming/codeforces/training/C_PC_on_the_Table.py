# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
#input = sys.stdin.readline
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

# IO
#input = sys.stdin.readline
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function

n, m = invr()

mtx = [list(input()) for _ in range(n)]

for lt in mtx:
    for i in range(m-1):
        if lt[i] == 'T' and lt[i+1] == 'T':
            lt[i], lt[i+1] = 'P', 'C'

for lt in mtx:
    print(''.join(map(str, lt)))
