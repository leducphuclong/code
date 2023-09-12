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
# Main function
for _ in range(inp()):
    s = input().strip()
    
    if len(set(s[0:len(s)//2])) > 1:
        print("YES")
    else:
        print("NO")