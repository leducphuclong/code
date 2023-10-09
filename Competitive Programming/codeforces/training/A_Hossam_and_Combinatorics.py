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
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    n = inp()
    arr = inlt()
    d = abs(min(arr)-max(arr))
    cnt = defaultdict(lambda: 0)
    ans = 0
    for v in arr:
        ans += cnt[v-d]+cnt[v+d]
        cnt[v] += 1
    if d == 0:
        print(n*(n-1))
    else:
        print(ans*2)