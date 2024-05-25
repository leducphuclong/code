from collections import defaultdict
import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = []
for i in range(n):
	tmp = list(map(int, input().split()))
	while len(tmp) < 26:
		tmp.append(0)
	arr.append(tmp)

while len(arr) < 9:
	arr.append([0]*26)

q = int(input())

for _ in range(q):
	qry = input().strip()

	stack = list()

	i = len(qry)-1
	row, col = -1, -1

	while i >= 0:
		if qry[i] == '(':
			if row != -1:
				stack.append(str(arr[row][col]))
				row, col = -1, -1

			val = []
			while (stack[-1] != ')'):
				val.append(int(stack[-1]))
				stack.pop()
			stack.pop()


			opr = qry[i-3] + qry[i-2] + qry[i-1]
			if opr == "SUM":
				if len(val):
					stack.append(str(sum(val)))
			else:
				if len(val):
					stack.append(str(max(val)))

			i -= 4
		else:
			if qry[i] == ')':
				stack.append(')')
			elif qry[i].isdigit():
				row = int(qry[i])-1
			elif qry[i].isalpha():
				col = ord(qry[i]) - 65
			else: # qry[i] == ','
				if row != -1:
					# print(row, col)
					stack.append(str(arr[row][col]))
			i -= 1

	if row != -1:
		stack.append(str(arr[row][col]))

	if len(stack):
		print(*stack)
	else:
		print(0)

