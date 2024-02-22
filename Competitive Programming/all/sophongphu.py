import math

l = int(input())
r = int(input())

dem = 0
for x in range(l, r+1):
	#x là 1 số trong đoạn l,r
	sm = 0 # tong cac uoc cua x
	for i in range(1, int(math.sqrt(x))+1):
		if x % i == 0:
			sm += i + x//i
	if (int(math.sqrt(x)) == float(math.sqrt(x))):
		sm -= int(math.sqrt(x))n
	sm -= x
	if sm > x:
		dem += 1

print(dem)
