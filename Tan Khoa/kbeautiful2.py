INF = int(1e9)

for _ in range(int(input())):
	n = int(input())
	arr = list(map(int, input().split()))
	arr.insert(0, -1)

	dis = [-INF]*(n+1)
	pos = [0]*(n+1)

	for i in range(1, n+1):
		dis[arr[i]] = max(dis[arr[i]], i-pos[arr[i]])
		pos[arr[i]] = i

	for i in range(1, n+1):
		dis[i] = max(dis[i], n-pos[i]+1)

	val = [INF]*(n+1)

	for i in range(1, n+1):
		val[dis[arr[i]]] = min(val[dis[arr[i]]], arr[i])

	for i in range(1, n+1):
		val[i] = min(val[i], val[i-1])
		if (val[i] != INF):
			print(val[i], end = ' ')
		else:
			print(-1, end = ' ')

	print()
	