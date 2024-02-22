n, s = map(int, input().split())

arr = list(map(int, input().split()))

cur = 0

left, right = 0, 0
ans = -1

while right < n:
	if (cur + arr[right] < s):
		cur += arr[right]
		right += 1
	else:
		if ans == -1 or right - left + 1 <= ans:
			ans = right - left + 1
		cur -= arr[left]
		left += 1


print(ans)



