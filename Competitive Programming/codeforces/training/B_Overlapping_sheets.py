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
C, R = 105, 105
# IO
#input = sys.stdin.readline
# sys.stdin = open('in.txt', 'r')
# sys.stdout = open('out.txt', 'w')
# Main function
pfs = [[0 for x in range(C)] for y in range(R)]

q = inp()
for _ in range(q):
    x, z, y, t = invr()
    x += 1; z += 1; y += 1; t += 1
    for i in range(x, z):
        for j in range(y, t):
            pfs[i][j] += 1

cnt = 0

for i in range(1, 101):
    for j in range(1, 101):
        if pfs[i][j] != 0:
            cnt += 1
    
print(cnt)

