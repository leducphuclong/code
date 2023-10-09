# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
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
n, m = invr()
arr = []
lose = defaultdict(int)



for _ in range(m):
    x, y = invr()
    lose[y] = x
    
    
ans = []
for i in range(1, n+1):
    if lose[i] == 0:
        ans.append(i)

if len(ans) == 1:
    print(*ans)
else:
    print(-1)
    