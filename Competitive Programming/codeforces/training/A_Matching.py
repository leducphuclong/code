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
for _ in range(inp()):
    s = instr()
    if (s[0] == '0'):
        print(0)
    else:
        ans = 1
        if s[0] == '?':
            ans *= 9
        for i in range(1, len(s)):
            if s[i] == '?':
                ans *= 10
        print(ans)
            