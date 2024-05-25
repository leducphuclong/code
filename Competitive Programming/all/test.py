# Copyright (c) 2024, Le Duc Phuc Long
 
# If you don't think twice, you have to code twice.

import sys
 		
# IO



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
test = fastpow(3, fastpow(4, 0, 100000), 5) 
test *= fastpow(3, fastpow(4, 1, 100000), 5)
test *= fastpow(2, fastpow(4, 3, 100000), 5)
print(test)
exit()
x, y, n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

xp = [1]*n # xp[i] is x^i
for i in range(1, n):
	xp[i] = xp[i-1]*x%k

ta = 0 # this is the number a in 10-based
for i in range(n):
	ta += a[i]%k*xp[i]%k
	ta %= k

yp = [1]*m # xp[i] is x^i
for i in range(1, m):
    yp[i] = yp[i-1]*y

tb = 0 # this is the number b in 10-based
for i in range(m):
	tb += b[i]*yp[i]



if not ta and not tb:
	print(1)
else:
	print(fastpow(ta, tb, k))









 