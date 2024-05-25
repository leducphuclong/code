a, b = map(int, input().split())

if b > 9:
	b = b//10

if a > b:
	print("A")
else:
	print("B")