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
limit = 2**33
# Main function
# sys.stdin = open('in.txt', 'r')
# sys.stdout = open('out.txt', 'w')
for _ in range(inp()):
    # Input
    n = inp()
    afraid = inlt()
    # Case all elements equal to 1
    if afraid[0] == 1 and len(set(afraid)) == 1:
        print(1, 1)
        continue
    # Case data exceed limit
    product = 1
    for v in afraid:
        product *= v
        if product > limit:
            break
    if product > limit:
        l, r = 0, n - 1
        while l < n and afraid[l] == 1:
            l += 1
        while r >= 0 and afraid[r] == 1:
            r -= 1
        print(l + 1, r + 1)
        continue
    # Here, this list will have at most 64 elements > 1
    afraid.insert(0, 0)
    # find index of all that elements
    idx = []
    for i in range(1, n+1):
        if afraid[i] > 1:
            idx.append(i)
    m = len(idx)
    # Build prefix sum with direct from left to right
    pfs_l2r = [0]*(n+1)
    for i in range(1, n+1):
        pfs_l2r[i] = pfs_l2r[i-1]+afraid[i]
    # Build prefix sum with direct form left to right
    pfs_r2l = [0]*(n+2)
    for i in range(n, 0, -1):
        pfs_r2l[i] = pfs_r2l[i+1]+afraid[i]
    # Build prefix proder sum with direct form left to right
    pfp = [1]*(n+1)
    for i in range(1, n+1):
        pfp[i] = pfp[i-1]*afraid[i]
    # find optimal answer
    ans, left, right = 0, 0, 0
    for i in range(m):
        for j in range(i, m):
            l, r = idx[i], idx[j]
            total = pfs_l2r[l-1]+pfs_r2l[r+1]+pfp[r]//pfp[l-1]
            if total > ans:
                ans = total
                left, right = l, r
    print(left, right)
# 4
# 1 1 2 3
    
# 3 4