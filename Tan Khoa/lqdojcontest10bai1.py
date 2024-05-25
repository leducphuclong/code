import sys
from collections import defaultdict

input = sys.stdin.readline

s = input()

cnt = defaultdict(lambda : 0)

for c in s:
	cnt[c] += 1

norm = "Chuc mung sinh nhat LQDOJ"
for c in norm:
	cnt[c] -= 1

res = 0
for key, value in cnt.items():
	if value < 0:
		# print(key, value)
		res += abs(value)

print(res)