# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
#input = sys.stdin.readline
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
#input = sys.stdin.readline
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function

n = inp()
arr = inlt()

cnt = defaultdict(int)

for v in arr:
    cnt[v] += 1

ans = 0
for val in cnt.values():
    ans += val//2

print(ans)