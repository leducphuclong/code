import sys

input = sys.stdin.readline

n, m = map(int, input().split())

tastes = []
for _ in range(m):
	x = int(input())
	tastes.append(x)

total = sum(tastes)

e = total // n

maxCandy = 0

for qtt in tastes:
	if round(qtt/e) > qtt/e:
		maxCandy = max(maxCandy, e)
	else:
		maxCandy = max(maxCandy, e+1)
		
print(maxCandy)