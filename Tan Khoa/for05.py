from math import sqrt
from sys import stdin

input = stdin.readline

n = int(input())

s = 0


for i in range(1, int(sqrt(n)) + 1):
	if n % i == 0:
		d1 = i; d2 = n//i
		if d1 == d2:
			s += d1
		else:
			s += (d1  + d2)

if s == n*2:
	print("YES")
else:
	print("NO")
