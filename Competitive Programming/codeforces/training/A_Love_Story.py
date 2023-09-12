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

def insr():
    return list(input().strip())

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
# Precompute
norm = "codeforces"
# Main function
for _ in range(inp()):
    cnt = 0
    s = insr()
    for i in range(len(s)):
        if s[i] != norm[i]:
            cnt += 1
    print(cnt)