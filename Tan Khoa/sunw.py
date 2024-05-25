from sys import stdin
from collections import defaultdict

input = stdin.readline

n, x = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()

cnt = defaultdict(lambda : 0)

for v in arr:
	cnt[v] += 1

l = 0; r = n-1
ans = 0

while l < r:
	if arr[l] + arr[r] <= x:
		ans += 1 
		l += 1; r -= 1
	else:
		
		
