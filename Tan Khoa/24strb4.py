from math import sqrt

def isSquare(n):
	return sqrt(n) == int(sqrt(n))

def bruteforce(n):
	cnt = 0
	for i in range(1, n**2+1):
		if isSquare(n**2 + i**2) == True:
			cnt += 1
	return cnt

n = int(input())

dvs = set()
for i in range(1, int(sqrt(n))+1):
	if n % i == 0:
		dvs.add(i)
		dvs.add(n//i)
dvs = list(dvs)
dvs.sort()

# for v in dvs:
# 	print(v, end = ' ')
# print()

# print()
# for v in dvs:
# 	if v % 2 == 0:
# 		print(v, end = ' ')
# print()


cnt = 0
for d in dvs:
	s = n//d; S = n*d 
	if (S+s) % 2 == 1 or (S-s) % 2 == 1:
		continue
	y = (S+s)//2; x = (S-s)//2
	if x > 0 and y > 0:
		# print(x, y)
		cnt += 1

# print(cnt)

odd, eve = 0, 0
for d in dvs:
	if d % 2 == 1 and n // d % 2 == 1:
		odd += 1
	if n // d % 2 == 0:
		print("d: ", )
		eve += 1
print(odd, "~", eve)

print(bruteforce(n))
print(odd*(odd-1)//2 + eve*(eve-1)//2)

