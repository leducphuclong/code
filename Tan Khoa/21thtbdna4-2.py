import sys
input = sys.stdin.readline

n, k, m = map(int, input().split())

g = n // k + 1
if m < g:
	print(k*m)
else:
	if n % k == 0:
		m -= 1; g -= 1
	print(m//g + m%g*k)


