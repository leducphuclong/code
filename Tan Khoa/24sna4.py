import sys

input = sys.stdin.readline

n, d = map(int, input().split())

arr = list(map(int, input().split()))

arr.sort()

i, cnt = 0, 0

while i < n:
	if i < n- 1 and arr[i+1] - arr[i] <= d:
		i += 1
		cnt += 1
	i += 1

print(cnt)


