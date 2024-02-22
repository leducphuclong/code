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
    odd, eve = [], []
    for i in range(n):
        if arr[i] % 2 == 1:
            odd.append(i+1)
        else:
            eve.append(i+1)
    if len(odd) >= 3:
        print("YES")
        print(odd[0], odd[1], odd[2])
    elif len(odd) >= 1 and len(eve) >= 2:
        print("YES")
        ans = [odd[0], eve[0], eve[1]]
        ans.sort()
        print(*ans)
    else:
        print("NO")