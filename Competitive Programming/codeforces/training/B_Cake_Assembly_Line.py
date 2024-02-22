# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline
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
input = sys.stdin.readline
#sys.stdin = open('in.txt', 'r')
#sys.stdout = open('out.txt', 'w')
# Main function
for _ in range(inp()):
    n, w, h = invr()
    a = inlt()
    b = inlt()
    
    """_summary_
    call the new pos of ai is ci: ci = ai+p
    ci have to sastified with:
        -> ci+w = bi+h (shift to left most)
        -> ci-w = bi-h (shift to right most)
    (Explain: if ci+w = bi+h-1, then the chocolate will fall to floor)
        -> min(ci) = bi+h-w 
        -> max(ci) = bi-h+w 
    => 
        bi+h-w <= ci <= bi-h+w
    =>
        bi+h-w <= ai+p <= bi-h+w (replace ci = ai+p)
    =>
        bi+h-w-ai <= p <= bi-h+w-ai
    => If there is a posible solution, then p must be exist
    =>
        bi+h-w-ai <= bi-h+w-ai (with every i)
    -> Above is the posivble range of cake i
    -> If we want to shift, we have to find a find properly with all i
    -> So we find the intersection of all these ranges
    """
    l = -9999999999990
    r = 99999999999999
    for i in range(n):
        l = max(b[i]+h-w-a[i], l)
        r = min(b[i]-h+w-a[i], r)
    
    # print(l, r)
    
    if (l <= r):
        print("YES")
    else:
        print("NO")
        
    
    
    
   
        
    
    
    
    

    

    
    
    