# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return int(input())

def inlt():
    return list(map(int, input().split()))

def insr():
    s = input()
    return list(s[:len(s) - 1])

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
# Main function
for _ in range(inp()):
    a, b = invr()
    tso = inlt()
    ten = inlt()
    
    t1 = sum(tso);
    t2 = sum(ten);
    
    if t1 > t2:
        print("Tsondu")
    elif t1 < t2:
        print("Tenzing")
    else:
        print("Draw")