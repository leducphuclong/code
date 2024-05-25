from collections import defaultdict

fact = [1]*12
for i in range(1, 12):
	fact[i] = fact[i-1]*i 

pow10 = [1]*12
for i in range(1, 12):
	pow10[i] = pow10[i-1]*10

def cal(n):
	cnt = defaultdict(lambda: 0)
	for c in str(n):
		cnt[int(c)] += 1

	l = len(str(n))

	res = 0

	for i in range(l):
		for d in range(10):
			if not cnt[d]:
				continue
			p = fact[l-1]
			cnt[d] -= 1
			for v in range(10):
				if cnt[v]:
					p //= cnt[v]

			cnt[d] += 1
			res += p*d*pow10[i]

	return res

n = int(input())

if '0' in str(n):
	tmp = ""
	for c in str(n):
		if c != '0':
			tmp += c

	m = int(tmp)

	print(cal(n) - cal(m))
else:
	print(cal(n))
