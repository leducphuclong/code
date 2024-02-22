# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
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
def sum_of_sequence(l, r, s):
    return (r+l)*((r-l)//s+1)//2
# Precompute
MOD = int(1e9)+7
fact = [1]
for i in range(1, int(1e5)+1):
    fact.append(fact[-1]*i % MOD)
# IO
input = sys.stdin.readline
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function
print(sum_of_sequence(1, int(2e5), 1))
for _ in range(inp()):
    n = inp()
    print(fact[n-1]*n*2*sum_of_sequence(1, n-1, 1)%MOD)