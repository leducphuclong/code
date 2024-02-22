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

############ ---- Other Functions ---- ############
# Main function
for _ in range(inp()):
    n, k = invr()
    arr = inlt()
    tmp = []
    for i in range(0, n-1):
        tmp.append(abs(arr[i+1]-arr[i]))
    tmp.sort()
    for __ in range(k-1):
        tmp.pop()
    print(sum(tmp))
        