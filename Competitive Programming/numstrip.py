n = int(input())
arr = list(map(int, input().split()))

# tao mang prefix sum
pfs = [0]

for v in arr:
    pfs.append(pfs[-1]+v)

dem = 0

for i in range(1, n):
    if pfs[i] == pfs[n] - pfs[i]:
        dem += 1

print(dem) 