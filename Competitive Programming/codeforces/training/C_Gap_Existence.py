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

n, x = invr()
arr = inlt()

exist = defaultdict(lambda: False)

if x == 0:
    print("Yes")
    exit()

for v in arr:
    y1 = v-x
    y2 = v+x
    if exist[y1] or exist[y2]:
        print("Yes")
        exit()
    exist[v] = True

print("No")