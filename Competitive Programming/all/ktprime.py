import math
t = int(input())
for i in range(t):
	n = int(input())
	cnt = 0
	for i in range(2, int(math.sqrt(n))+1):
		if n % i == 0:
			if i % 2 == 0:
				cnt += 1
			if n//i % 2 == 0:
				cnt += 1
	if int(math.sqrt(n)) == float(math.sqrt(n)) and int(math.sqrt(n)) % 2 == 0:
		cnt -= 1
	if n % 2 == 0:
		cnt += 1
	print(cnt)
