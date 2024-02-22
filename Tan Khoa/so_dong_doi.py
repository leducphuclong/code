n = int(input())

i = 1
cnt = 0

while i*i <= n:
	if n % i == 0:
		d1, d2 = i, n//i
		t1, t2 = n-d1, n-d2
		if t1 % d1 == 0:
			cnt += 1
		if t2 != 0 and d1 != d2 and (d2 % t2 == 0 or t2 % d2 == 0):
			cnt += 1
	i += 1

if not n & 1:
	print(2*cnt - 1)
else:
	print(2*cnt)
