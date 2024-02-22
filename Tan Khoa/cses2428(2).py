from collections import defaultdict

n, k = map(int, input().split())
arr = list(map(int, input().split()))

left, right = 0, 0
ans = 0

cnt = defaultdict(lambda: 0)
s = set()

while right < n:
	if len(s) + 1 <= k or arr[right] in s:
		cnt[arr[right]] += 1 
		s.add(arr[right])
		ans += right - left + 1
		right += 1
	else:
		cnt[arr[left]] -= 1
		if cnt[arr[left]] == 0:
			s.remove(arr[left])
		left += 1

print(ans)