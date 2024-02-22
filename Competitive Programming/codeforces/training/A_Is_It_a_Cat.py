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
cat = "MEOW"
cnt = defaultdict(int)
for i in range(len(cat)):
        cnt[cat[i]] = i+1
# Main function
for _ in range(inp()):
    n = int(input())
    s = input().strip()
    s = s.upper()
    check = True
    qtt = 1
    for i in range(len(s)-1):
        if cnt[s[i]] > cnt[s[i+1]] or cnt[s[i]] == 0:
            check = False
        elif cnt[s[i]] < cnt[s[i+1]]:
            qtt += 1
    if check and qtt == 4:
        print("YES")
    else:
        print("NO")
    
    
