n, k = map(int, input().split())
arr = list(map(int, input().split()))

s = arr[0]

del arr[0]

arr.sort(reverse = Tr	ue)

for i in range(n-1):
	if (i <= k-1):
		s += arr[i]
	else:
		s -= arr[i]

print(s)

