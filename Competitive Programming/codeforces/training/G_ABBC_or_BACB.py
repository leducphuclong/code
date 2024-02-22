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
# sys.stdin = open('in.txt', 'r')
# sys.stdout = open('out.txt', 'w')
# Main function

n = inp()
for _ in range(n):
    s = instr()

    cur, ans = 0, 0
    for i in range(len(s)):
        c = s[i]
        if c == 'B':
            s[i] = 'A'
            ans += cur
            cur = 0
        else:
            cur += 1
    

    if 'B' in s and cur != 0:
        ans += cur

    print(ans)
