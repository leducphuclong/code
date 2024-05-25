# Copyright (c) 2024, Le Duc Phuc Long
 
# If you don't think twice, you have to code twice.

import sys
 		
# IO
input = sys.stdin.readline
#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def fastpow(n, m, p):
	res = 1
	while m > 0:
		if m & 1:
			res *= n; res %= p
		m //= 2
		n *= n
		n %= p
	return res
	

# Main function

x, y, n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

chk_a = False; chk_b = False
for v in a:
	if v:
		chk_a = True
for v in b:
	if v:
		chk_b = True

if not chk_a and not chk_b:
	print(1)
	exit()

xp = [1]*n # xp[i] is x^i
for i in range(1, n):
	xp[i] = xp[i-1]*x%k

ta = 0 # this is the number a in 10-based
for i in range(n):
	ta += a[i]%k*xp[i]%k
	ta %= k

# now we have to calculate: 
# -> product of ta^(b[i]*y^i) with i from 0 -> m-1
# Instead, we calculate:
# product of (ta^b[i])^y^i with i from 0 -> m-1

tmp = [1]*(m)
for i in range(m):
	tmp[i] = fastpow(ta, b[i], k)

yp = [1]*m # xp[i] is x^i
for i in range(1, m):
    yp[i] = yp[i-1]*y

p = [1]*(m+1)
for i in range(m):
	p[i] = fastpow(tmp[i], yp[i], k)

ans = 1
for i in range(m):
	ans *= p[i]
	ans %= k

print(ans)









 