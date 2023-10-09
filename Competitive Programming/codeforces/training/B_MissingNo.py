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
arr.sort()
check = defaultdict(lambda: 0)
cnt, sav = 0, 0
for v in arr:
    if check[v-1] == 0:
        cnt += 1
        if cnt == 2:
            sav = v-1
    check[v] += 1

print(sav)