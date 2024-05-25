n, k, m = map(int, input().split())

if n % k == 0:
	g = n // k + 1
	if m < g:
		print(k*m)
	else:
		print((m-1)//(g-1) + (m-1)%(g-1)*k)

else:
	g = n//k + 1 
	if m < g:
		print(k*m)
	else:
		print(m//g + m%g*k)