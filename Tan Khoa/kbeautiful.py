INF = int(1e9)

for _ in range(int(input())):
	n = int(input())
	arr = list(map(int, input().split()))

	arr.insert(0, 0)

	pos = [0]*(n+1)
	dis = [0]*(n+1)

	for i in range(1, n+1):
		dis[arr[i]] = max(dis[arr[i]], i - pos[arr[i]])
		pos[arr[i]] = i

	for i in range(1, n+1):
		dis[i] = max(dis[i], n - pos[i] + 1)

	res = [INF]*(n+2)

	for i in range(1, n+1):
		res[dis[i]] = min(res[dis[i]], i)

	for i in range(1, n+1):
		res[i] = min(res[i], res[i-1])
		if (res[i] != INF):
			print(res[i], end = ' ')
		else:
			print(-1, end = ' ')
	print()

