from math import sqrt

l, r = map(int, input().split())

M = int(1e6)

dvs = [1]*(M+1);

for i in range(2, int(round(sqrt(M)))+1):
    for j in range(i, M, i):
        dvs[j] += 1

cnt = [0]*(M+1);
for x in range(1, M+1):
    cnt[x] = cnt[x-1]
    if (dvs[x]%2):
        cnt[x] += 1

print(0)

for i in range(l, r+1):
    print(dvs[l+i], end = " ");   
