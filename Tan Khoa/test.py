# Copyright (c) 2024, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
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

# Precompute
s = [0]*20
s[1] = 45
for i in range(2, 7):
    s[i] = s[i-1]*10 + 45*int(pow(10, i-1))

############ ---- Other Functions ---- ############
def sum(n):
	return ((n-1)+1)*(n+1)//2

def first_digit(n):
	return int(str(n)[0])

def cal(n):
	# print(n)
	if n < 10:
		return sum(n)
	f, l = first_digit(n), len(str(n))
	r = n % int(pow(10, l-1))
	# print(f, l, r)
	# print(sum(f-1))
	return f*s[l-1] + sum(f-1)*(int(pow(10, l-1))) + f*(r+1) + cal(r)

# IO
input = sys.stdin.readline

# Main function
for _ in range(inp()):
	n = inp()
	print(cal(n))
