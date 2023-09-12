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

def instr():
    s = input()
    return list(s[:len(s) - 1])

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
# Main function
for _ in range(inp()):
    n = inp()
    s = instr()
    tmp, ans = s[0], ""
    i = 1
    while i < n:
        if s[i] == tmp:
            ans += tmp
            if (i < n-1):
                tmp = s[i+1]
                i += 1
        i += 1
    print(ans)
        