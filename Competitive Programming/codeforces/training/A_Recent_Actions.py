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

def instr():
    return list(input().strip())

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
# Precompute
    
# Main function
for _ in range(inp()):
    n, m = invr()
    arr = inlt()
    cnt = defaultdict(int)
    ans = []
    for i in range(m):
        if cnt[arr[i]] == 0 and len(cnt) <= n:
            ans.append(i)
        cnt[arr[i]] = 1
    for i in range(max(n-len(cnt), 0)):
        print(-1, end = ' ')
    ans.reverse()
    for v in ans:
        print(v+1, end = ' ')
    print()