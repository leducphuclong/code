l = int(input())
r = int(input())

sms = [1]*(r+1)

for i in range(2, r+1):
	for j in range(i*2, r+1, i):
		sms[j] +=  i

dem = 0
for i in range(l, r+1):
	if sms[i] > i:
		dem += 1

print(dem)

