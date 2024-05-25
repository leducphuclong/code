import sys

input = sys.stdin.readline

def sumDigits(n):
	res = 0
	while n > 0:
		res += n % 10 
		n //= 10
	return res

l, r = map(int, input().split())

N = int(3e6) + 5

isPrime = N*[True]

isPrime[0] = isPrime[1] = False

i = 2
while i*i < N:
	if isPrime[i] == True:
		for j in range(i*i, N, i):
			isPrime[j] = False
	i += 1


pfs = N*[0]
for i in range(1, N):
	pfs[i] = pfs[i-1] + (isPrime[i] and sumDigits(i) % 5 == 0)

print(pfs[r] - pfs[l-1])