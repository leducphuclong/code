n = int(input())
arr = list(map(int, input().split()))

pfs = [0]
for value in arr:
    pfs.append(pfs[-1]+value)

dem = 0
for i in range(1, n):
    if (pfs[i] == pfs[n]-pfs[i]):
        dem += 1

print(dem)
