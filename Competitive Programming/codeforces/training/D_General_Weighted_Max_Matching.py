# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
#input = sys.stdin.readline
from collections import defaultdict
from math import *

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
drr = [[0 for x in range(n)] for y in range(n)]
for i in range(n-1):
    d = inlt()
    for j in range(i+1, n):
        drr[i][j] = drr[j][i] = d[j-i-1]

def dfs(used):
    if (all(used)):
        return 0
    v = used.index(False)
    used[v] = True
    total = 0
    for i in range(n):
        if not used[i]:
            used[i] = True
            total = max(total, dfs(used)+drr[v][i])
            used[i] = False
    used[v] = False
    return total

ans = 0
used = [False]*(n)

if n % 2 == 0:
    ans = dfs(used)
else:
    for i in range(n):
        used[i] = True
        ans = max(ans, dfs(used))
        used[i] = False
    
print(ans)
