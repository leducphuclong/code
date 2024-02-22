from collections import defaultdict

n, k = map(int, input().split())
arr = list(map(int, input().split()))

left, right = 0, 0
ans = 0

cnt = defaultdict(lambda: 0)
exist = dict()

while right < n:
	if len(exist) + 1 <= k or arr[right] in exist:
		cnt[arr[right]] += 1
		exist[arr[right]] = True
		ans += right - left + 1
		right += 1
	else:
		cnt[arr[left]] -= 1
		if cnt[arr[left]] == 0:
			exist.pop(arr[left])
		left += 1


print(ans)