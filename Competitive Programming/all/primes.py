import math

n = int(input())
arr = list(map(int, input().split()))

mav = int(1e9)
res = -99999999

for i in arr:
	is_prime = 1
	if i > 2 and i % 2 == 0:
		is_prime = 0
		continue
	if i > 3 and i % 3 == 0:
		is_prime = 0
		continue
	if i > 5 and i % 5 == 0:
		is_prime = 0
		continue
	if i > 7 and i % 7 == 0:
		is_prime = 0
		continue
	if i > 11 and i % 11 == 0:
		is_prime = 0
		continue
	for j in range(2, int(math.sqrt(i)+1)):
		if i % j == 0:
			is_prime = 0
			break;
	if is_prime and i > res:
		res = i

print(res)
for i in range(n):
	if arr[i] == res:
		print(i+1, end = " ")


