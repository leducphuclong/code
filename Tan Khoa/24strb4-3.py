from math import *

n = int(input())

N = int(1e6+5)

isPrime = [True]*N
isPrime[0] = isPrime[1] = False
for i in range(2, round(sqrt(n))):
	if isPrime[i] == False:
		continue
	for j in range(i*i, N, i):
		isPrime[j] = False

primes = []
for i in range(N):
	if isPrime[i] == True:
		primes.append(i)

if n % 2 == 1:
	s, i, p = 1, 0, 0
	while n > 1 and i < len(primes):
		if n % primes[i] == 0:
			p = 0
			while n % primes[i] == 0:
				n //= primes[i]
				p += 1
			s *= (p*2+1)
		i += 1
	if n > 1:
		s *= 2
	print(s//2)
else:
	s, i, p = 1, 0, 0
	while n % primes[i] == 0:
		n //= primes[i]
		p += 1
	s *= (p*2 - 1)
	i += 1
	while n > 1 and i < len(primes):
		if n % primes[i] == 0:
			p = 0
			while n % primes[i] == 0:
				n //= primes[i]
				p += 1
			s *= p*2+1
		i += 1
	print(s//2)


