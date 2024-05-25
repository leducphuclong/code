from math import *

def bcnn(a, b):
	return a*b//gcd(a, b)

t = list(map(int, input().split()))
x, s = map(int, input().split())

for i in range(len(t)):
	t[i] += x

res = 1
for v in t:
	res = bcnn(res, v)

if res > s:
	print(res-s)
else:
	print(res*ceil(s/res) - s)

