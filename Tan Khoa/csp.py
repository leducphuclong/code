import sys
from collections import defaultdict

input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()

# cnt[v] se la so lan xuat hien v
cnt = defaultdict(lambda : 0)
for v in arr:
	cnt[v] += 1

l = 0; r = n-1
ans = 0
while l < r:
	if arr[l] + arr[r] <= m:
		ans += r-l
		l += 1
	else:
		r -= 1

print(ans)


