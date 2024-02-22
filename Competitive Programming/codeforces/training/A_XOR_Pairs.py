# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
#input = sys.stdin.readline
from collections import defaultdict
from math import floor, log2, pow
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
arr = inlt()

mrk = defaultdict(lambda: False)
for v in arr:
    mrk[v] = True

ans = 0    
for i in range(1, n+1):
    if mrk[i] == True:
        continue
    ans += i-pow(2, floor(log2(i)))

print(round(ans)*2)