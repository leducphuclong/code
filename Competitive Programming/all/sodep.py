n = int(input())

xuat_hien = 0
cnt = 0
while n > 0:
	num = n % 10
	if not xuat_hien:
		if abs(num-7) < abs(num-3):
			cnt += abs(num-7)
		else:
			cnt += abs(num-3)
			xuat_hien = 1
	else:
		if num == 1:
			cnt += 4
		else:
			cnt += abs(num-3)
	n //= 10	
	
print(cnt)