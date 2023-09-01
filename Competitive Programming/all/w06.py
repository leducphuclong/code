import math

a, b = map(int, input().split())

while a != b:
	if a > b:
		a -= b
	else:
		b -= a 

res = []

for i in range(1, int(math.sqrt(b))+1):
	if b % i == 0:
		res.append(i)
		if i != b//i:
			res.append(b // i)
res.sort()
for i in range(len(res)):
	print(res[i], end = "")
	if i < len(res)-1:
		print(" ", end = "")

