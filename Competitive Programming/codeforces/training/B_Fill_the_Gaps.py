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
n = inp()
arr = inlt()
for i in range(n-1):
    if abs(arr[i] - arr[i + 1]) == 1:
        print(arr[i], end = ' ')
        continue
    sign = (arr[i+1] - arr[i])//abs(arr[i] - arr[i+1])
    for j in range(arr[i], arr[i+1], sign):
        print(j , end = ' ')

print(arr[-1], end = ' ')