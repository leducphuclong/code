import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

cnt = 0
for i in range(1, n):
	if arr[i] < arr[i-1]:
		cnt += arr[i-1] - arr[i]
		arr[i] = arr[i-1]

print(cnt)


