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
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def compute_sequence(l, r):
    n = r - l + 1
    a = l
    d = 1

    sequence_sum = (n * (2 * a + (n - 1) * d)) // 2

    return sequence_sum

# Precompute
    
# Main function
for _ in range(inp()):
    n, x, y = invr()
    lcm = x*y//gcd(x, y)
    plus = n // x - n//lcm
    minus = n // y - n//lcm
    print(compute_sequence(n-plus+1, n)-compute_sequence(1, minus))
    