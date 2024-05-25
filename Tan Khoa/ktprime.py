from math import sqrt
from sys import stdin

input = stdin.readline

n = int(input())

check = True

# i --> n//i

# i*i --> n

# i --> sqrt(n)

if n < 2:
	check = False
else:
	for i in range(2, int(sqrt(n)) + 1):
		if n % i == 0:
			check = False

if check:
	print("YES")
else:
	print("NO")