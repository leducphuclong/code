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
    
# Main function
# sys.stdin = open('in.txt', 'r')
# sys.stdout = open('out.txt', 'w')
n = int(input())

dvs = []
for i in range(1, 10):
    if n % i == 0:
        dvs.append(n//i)

for i in range(n+1):
    ans = -1
    for d in dvs:
        if i % d == 0:
            ans = d
            break
    if ans == -1:
        print('-', end = "")
    else:
        print(n//ans, end = "")
