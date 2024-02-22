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
    n, m, k = invr()
    x, y = invr()
    ans = "YES"
    for __ in range(k):
        xx, yy = invr()
        if (x+y) % 2 == (xx+yy) % 2:
            ans = "NO"
    print(ans)