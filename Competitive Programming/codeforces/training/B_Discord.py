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
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function
n, m = invr()
arr = []
for i in range(m):  
    lst = inlt()
    arr.append(lst)

sav = defaultdict(lambda: False)
for i in range(m):
    for j in range(1, n):
        sav[(arr[i][j-1], arr[i][j])] = True
        sav[(arr[i][j], arr[i][j-1])] = True

cnt = 0
for i in range(1, n):
    for j in range(i+1, n+1):
        if sav[(i, j)] == False:
            cnt += 1

print(cnt)
        
