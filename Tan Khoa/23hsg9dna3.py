import sys
# sys.stdin=open('NTDX.INP','r')
# sys.stdout=open('NTDX.OUT','w')

def check(n):
	if n==2 or n==3: return True
	if n<2 or n%2==0 or n%3==0: return False
	for i in range(5, int(n**0.5)+1, 6):
		if n % i == 0 or n % (i+2) == 0:
			return False
	return True

def palinize(n):
	res = n; n //= 10
	while n:
		res = res*10 + n % 10; n //= 10
	return res

n = int(input())
cnt = 11 <= n
for i in range(10, int(1e5)+1):
	palin = palinize(i)
	if palin > n:
		break
	cnt += check(palin)

print(cnt)


