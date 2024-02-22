n, s = map(int, input().split())
arr = list(map(int, input().split()))

left, right = 0, 0
ans, cur = 0, 0

while (right < n):
	if cur + arr[right] <= s:
		ans += right - left + 1 
		cur += arr[right];
		right += 1
	else:
		cur -= arr[left]
		left += 1

print(ans)
