# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return int(input())

def inlt():
    return list(map(int, input().split()))

def insr():
    s = input()
    return list(s[:len(s) - 1])

def invr():
    return map(int, input().split())

# Main function
for _ in range(inp()):
    a, b, c = invr()
    if a + b >= 10 or a + c >= 10 or b + c >= 10:
        print("YES")
    else:
        print("NO")