n = int(input())
l = int(input())
r = int(input())

arr = [0]*(n+1)
for i in range(1, n+1):
	arr[i] = i 

for i in range(1, n+1-n%2, 2):
	temp = arr[i] 
	arr[i] = arr[i+1]
	arr[i+1] = temp	

sm = 0
for i in range(l, r+1):
	sm += arr[i]

print(sm)