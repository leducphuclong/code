n = int(input())

cnt = 0

for i in range(1, n+1):
	for j in range(1, n+1):
		if (i % j == 0 or j % i == 0) and (i+j == n):
			print(i, j)
			cnt += 1

print(cnt)