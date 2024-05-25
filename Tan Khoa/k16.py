from sys import stdin
from math import sqrt

# faster
input = stdin.readline

tc = int(input())

for _ in range(tc):
	n = int(input())
	cnt = 0
	for i in range(1, int(sqrt(n)) + 1):
		if n % i == 0:
			d1 = i; d2 = n//i

			if d1 % 2 == 0:
				cnt += 1

			if d2 != d1:
				if d2 % 2 == 0:
					cnt += 1 
	print(cnt)