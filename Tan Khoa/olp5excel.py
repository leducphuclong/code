from collections import defaultdict

n, m = map(int, input().split())

idx = defaultdict()

for i in range(65, 91):
	idx[chr(i)] = i-65

arr = []
for i in range(n):
	tmp = list(map(int, input().split()))
	arr.append(tmp)


q = int(input())
for _ in range(q):
	qry = input().strip()
	stack = list()

	i = len(qry)-1
	row, col = 0, 0
	while i >= 0:
		if qry[i] != '(':
			if qry[i] == ')':
				stack.append(')')
			else:
				if qry[i].isalpha():
					row = int(qry[i])-1
				elif qry[i].isdigit():
					col = idx[qry[i]]
				else:
					stack.append(arr[row][col])
			i -= 1
		else:
			stack.append(arr[row][col])
			opr = qry[i-3] + qry[i-2] + qry[i-1]
			val = []
			while (stack[-1] != ')'):
				if stack[-1].isdigit():
					col = int(stack[-1])-1
				elif stack[-1].isalpha():
					row = idx[stack[-1]]
				else:
					# print(col, row)
					# val.append([col, row])
					val.append(arr[col][row])	
				stack.pop()

			# print(col, row)
			# print()
			# val.append([col, row])
			val.append(arr[col][row])
			stack.pop()

			# for v in val:
			# 	print(v)
			# print()

			if opr == "SUM":
				stack.append(str(sum(val)))
			else:
				stack.append(str(max(val)))

			i -= 4

	print(*stack)

print()








