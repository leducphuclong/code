import sys
from math import sqrt

# faster
input = sys.stdin.readline

n = int(input())

# Tim uoc

'''
Để tìm ước
-> Chạy i từ 1 đến căn của n để kiểm tra xem i có phải là ước 
của n không.
-> Mọi ước i đều có một ước khác là n//i
'''

# i là ước của n
# thì ta sẽ suy ra được thêm một ước của n nữa: n//i

# 16

# 2 -> 16/2 = 8

# Chứa ước của n
dvs = [] 

for i in range(1, int(sqrt(n)) + 1):
	if n % i == 0:
		d1 = n//i; d2 = i
		if d1 == d2:
			dvs.append(d1)
		else:
			dvs.append(d1)
			dvs.append(d2)

dvs.sort()

print(*dvs)


