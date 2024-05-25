import sys 
from collections import defaultdict

input = sys.stdin.readline # faster

n, x = map(int, input().split())
arr = list(map(int, input().split()))

cnt = defaultdict(lambda : 0)
for v in arr:
	cnt[v] += 1

arr.sort()

l = 0; r = n-1
ans = 0

while l < r:
	if arr[l] + arr[r] < x:
		l += 1
	elif arr[l] + arr[r] > x:
		r -= 1
	else:
		if arr[l] != arr[r]:
			ans += cnt[arr[r]]
			l += 1
		else:
			ans += (cnt[arr[l]]-1)*cnt[arr[l]]//2
			break

print(ans)


