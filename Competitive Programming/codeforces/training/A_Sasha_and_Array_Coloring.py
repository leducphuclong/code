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
    n = inp()
    arr = inlt()
    
    if len(arr) == 1:
        print(0)
        continue
    arr.sort()
    ans = 0
    l, r = 0, n-1
    while l < r:
        ans += arr[r]-arr[l]
        l += 1
        r -= 1
    print(ans)