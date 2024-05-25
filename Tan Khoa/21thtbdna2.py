from math import sqrt
import sys
input = sys.stdin.readline

n = int(input())

dvs = []
dvs.append(0); dvs.append(1)

for i in range(2, n+1):
	dvs.append(1+i)

sqrt_n = int(sqrt(n))

ans = 0; mav = 0

for i in range(2, sqrt_n+1):
	for j in range(i*i, n+1, i):
		dvs[j] += (i + j//i)
		if dvs[j] > mav:
			mav = dvs[j]
			ans = j


print(ans)
