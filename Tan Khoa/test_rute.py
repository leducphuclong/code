def sum(n):
		t = 0
		for v in str(n):
			t += int(v)
		return t

for _ in range(int(input())):
	n = int(input())
	res = 0
	for i in range(1, n+1):
		res += sum(i)

	print(res)