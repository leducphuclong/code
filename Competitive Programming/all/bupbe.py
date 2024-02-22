n, k = map(int, input().split())
arr = list(map(int, input.split()))
arr.sort(reverse = 1)
sm = a[0]
j = 0 # j là vị trí của con búp bê có lõi lên 
for i in range(1, n):
	if arr[i] + k <= arr[j]:
		j += 1
	else:
		sm += arr[i]

print(sm)