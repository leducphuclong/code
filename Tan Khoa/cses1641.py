	n, x = map(int, input().split())
	arr = list(map(int, input().split()))

	elm = []
	for i in range(n):
		elm.append([arr[i], i])

	elm.sort()

	a, b, c =  -1, -1, -1

	for f in range(n-2):
		s, t = f+1, n-1;
		while (s < t):
			if elm[s][0] + elm[t][0] + elm[f][0] == x:
				a, b, c = elm[f][1], elm[s][1], elm[t][1]
				break
			elif elm[s][0] + elm[t][0] + elm[f][0] < x:
				s += 1
			else:
				t -= 1

	if a != -1:
		ans = [a+1, b+1, c+1]
		ans.sort()
		print(*ans)
	else:
		print("IMPOSSIBLE")




