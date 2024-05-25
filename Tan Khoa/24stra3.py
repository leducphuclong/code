n = int(input())

MIN = [0]*20
MIN[2] = 1
MIN[3] = 3
MIN[4] = 4
MIN[5] = 2
MIN[6] = 6
MIN[7] = 8
MIN[8] = 10
MIN[9] = 18
MIN[10] = 22
MIN[11] = 20
MIN[12] = 28
MIN[13] = 68
MIN[14] = 88

if n <= 14:
	print(MIN[n])
else:
	print(str(MIN[n % 7 + 7]) + ((n-7)//7)*"8")

if n % 2 == 0:
	print("1"*(n//2))
else:
	print('7'+"1"*(n//2-1))

