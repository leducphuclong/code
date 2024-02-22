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
n = int(input())

arr = list(map(int, input().split()))
arr.insert(0, 0)

INF = int(1e9)

# Xây dựng đoạn "Prefix sum left" với ý nghĩa
# đoạn con có độ dài chia hết cho 3, bắt đầu từ vị trí nào đó bên trái
# và kết thúc ở vị trí i có trọng số lớn nhất là pfs_left[i]
pfs_left = (n+1)*[-INF]
for i in range(3, n+1):
	pfs_left[i] = arr[i] + arr[i-1] + arr[i-2] + max(0, pfs_left[i-3])

for i in range(1, n+1):
	pfs_left[i] = max(pfs_left[i], pfs_left[i-1])

pfs_right = (n+2)*[-INF]
for i in range(n-2, 0, -1):
	pfs_right[i] = arr[i] + arr[i+1] + arr[i+2] + max(0, pfs_right[i+3])

for i in range(n, 0, -1):
	pfs_right[i] = max(pfs_right[i], pfs_right[i+1])

ans = -INF
for i in range(2, n+1):
	ans = max(ans, pfs_left[i-1] + pfs_right[i])
print(ans)


