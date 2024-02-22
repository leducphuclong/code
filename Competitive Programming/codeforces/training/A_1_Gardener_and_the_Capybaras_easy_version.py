# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
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
for _ in range(inp()):
    s = input().strip()
    prefix = s[0:2]
    if prefix == "aa" or prefix == "bb" or prefix == "ba":
        print(s[0], s[1], s[2:])
    else: # "ab"
        f = s.find('a', 2, len(s))
        if f == -1:  # abbbbbbbbb....
            print(s[0], s[1:-1], s[-1])
        else:
            print(s[0], s[1:f], s[f:])