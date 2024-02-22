# Copyright (c) 2023, Le Duc Phuc Long
 
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
 
############ ---- Other Functions ---- ############
# Precompute
 
# IO
input = sys.stdin.readline
#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

# Main function
n = int(input())
length = int(6e4) + 1
road = [0]*(length)
for _ in range(n):
	l, r = map(int, input().split())
	road[l] += 1
	road[r] -= 1

energy = 0
cover = [False]*(length)
for i in range(0, length):
	energy += road[i]
	cover[i] = energy > 0

max_cover = 0; cur_cover = 0
for i in range(0, length):
	if cover[i] == True:
		cur_cover += 1
		max_cover = max(max_cover, cur_cover)
	else:
		cur_cover = 0

print(max_cover)
