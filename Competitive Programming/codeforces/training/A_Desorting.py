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
    n = inp()
    arr = inlt()
    ans = 999999999
    not_sorted = False
    for i in range(n-1):
        if arr[i] <= arr[i+1]:
            ans = min(ans, (arr[i+1]-arr[i])//2+1)
        else:
            not_sorted = True
    if not_sorted:
        print(0)
    else:
        print(ans)