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
#input = sys.stdin.readline
#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

# Main function
for _ in range(int(input())):
	n, m, k = map(int, input().split())
	mtx = [[0]*(m+1)]
	pfs = [[0]*(m+1)]
	for __ in range(n):
		row = input().strip()
		mtx.append([0])
		pfs.append([0]*(m+1))
		for c in row:
			if c == 'A':
				mtx[-1].append(1)
			else:
				mtx[-1].append(-1)

	for i in range(1, n+1):
		for j in range(1, m+1):
			pfs[i][j] = pfs[i-1][j] + pfs[i][j-1] - pfs[i-1][j-1] + mtx[i][j]

	res = 0
	for i in range(1, n+1):
		for j in range(1, m+1):
			if (n-i+1)*(m-j+1) <= res:
				break
			for u in range(n, i-1, -1):
				for v in range(m, j-1, -1):
					if (u-i+1)*(v-j+1) <= res:
						break
					t = pfs[u][v] - pfs[u][j-1] - pfs[i-1][v] + pfs[i-1][j-1]
					if abs(t) <= k:
						res = max(res, (u-i+1)*(v-j+1))
	print(res)


	
    