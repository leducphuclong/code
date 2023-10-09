# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Illustration of the problem
# https://pasteboard.co/l9kQ8QZ4HrHi.jpg

# Import session
import sys
# input = sys.stdin.readline
from collections import defaultdict
from math import sqrt, radians, tan, pi

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
def volume(r, h):
    return 1/3*pi*r**2*h
# Precompute
tan_ = tan(radians(34))    
# Main function
# sys.stdin = open('in.txt', 'r')
h, d = invr()
DF = h*d/(2*(h+d/2*tan_))
# print(DF)
GF = tan_*DF
# print(GF)
V1 = volume(DF, GF)
# print(V1)
FA = h-GF
V2 = volume(DF, FA)
V = V1+V2
print(format(V, "0.6f"))