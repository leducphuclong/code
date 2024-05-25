from math import *

def f(n):
	res = 0
	i = 2
	while i <= n:
		res += n // i
		i *= 2
	return res


l, r = map(int, input().split())
print(f(r) - f(l-1))
