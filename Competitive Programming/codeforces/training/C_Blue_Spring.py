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
n, d, p = invr()
f = inlt()

f.sort(reverse = True)

ans, cur = 0, 0
for i in range(1, n+1):
    cur += f[i-1]
    if i % d == 0:
        ans += min(cur, p)
        cur = 0

ans += min(cur, p)

print(ans)