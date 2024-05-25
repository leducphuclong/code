from math import *
import sys
input = sys.stdin.readline



n, a, b = map(int, input().split())

LIM = n+5

d = [2]*LIM
d[0] = 0
d[1] = 1
for i in range(2, round(sqrt(LIM))):
	for j in range(i*i, LIM, i):
		d[j] += 2
	d[i*i] -= 1

prm = []
for i in range(1, n+1):
	if d[i] == 2:
		prm.append(i)

def f(n):
	res = 1; i = 0
	while n > 1:
		if n % prm[i] == 0:
			res *= prm[i]
			while n % prm[i] == 0:
				n //= prm[i]
		else:
			i += 1
	return res

cnt = 0
for i in range(1, n):
	if f(i)*i <= n and a <= d[i] <= b:
		cnt += 1

print(cnt)










