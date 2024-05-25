from itertools import product

def allPerms(permutation_length):
	# Define your list and the length of permutations
	my_list = [1, 3, 5, 7, 9]

	# Generate permutations with repetitions
	perms = product(my_list, repeat=permutation_length)
	perms = list(perms)
	perms_string = []
	for perm in perms:
		s = ""
		for d in perm:
			s += str(d)
		perms_string.append(s)
	return perms_string

def noPalin(n):
	int_n = int(n)
	res = 0
	for i in range(1, len(n)//2+1):
		if (i*2 - 1 < len(n)):
			res += pow(5, i)
		if (i*2 < len(n)):
			res += pow(5, i)

	perms = allPerms(len(n) // 2 + (len(n) % 2 == 1))
	for perm in perms:
		if len(n) % 2 == 0:
			p = perm + perm[::-1]
		else:
			p = perm + perm[-2::-1]
		if (checkPalin(p) and int(p) <= int_n):
				res += 1
	return res

def checkPalin(n):
	l, r = 0, len(n)-1
	while (l < r):
		if n[l] != n[r]:
			return False 
		l += 1; r -= 1
	return True

def checkOdd(n):
	digits = {1, 3, 5, 7, 9}
	for d in n:
		if int(d) not in digits:
			return False
	return True

def noPalinBrute(n):
	m = int(n)
	cnt = 0
	for i in range(m+1):
		if checkOdd(str(i)) and checkPalin(str(i)):
			# print(i)
			cnt += 1
	return cnt


l, r = map(str, input().split())
if int(l) <= 1:
	print(noPalin(r))
else:
	print(noPalin(r) - noPalin(str(int(l)-1)))





