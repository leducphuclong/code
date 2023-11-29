n = input()
n = list(n)
n.reverse()
n = ''.join(n)

pow2, res = 0, 0

for x in n:
	if x == '1':
		res += pow2
	pow2 *= 2

print(res)