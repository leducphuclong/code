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
n = inp()
if n < int(1e3):
    print(n)
elif n < int(1e4):
    print(n-n%int(10))
elif n < int(1e5):
    print(n-n%int(1e2))
elif n < int(1e6):
    print(n-n%int(1e3))
elif n < int(1e7):
    print(n-n%int(1e4))
elif n < int(1e8):
    print(n-n%int(1e5))
else:
    print(n-n%int(1e6))