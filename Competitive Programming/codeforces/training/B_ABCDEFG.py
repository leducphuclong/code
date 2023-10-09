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
loc = defaultdict(lambda: 0)
loc['A'] = 0
loc['B'] = 3
loc['C'] = 4
loc['D'] = 8
loc['E'] = 9
loc['F'] = 14
loc['G'] = 23

p, q = map(str, input().split())

print(abs(loc[p]-loc[q]))