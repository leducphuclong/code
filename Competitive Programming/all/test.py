n = int(input())
arr = list(map(int, input().split()))

pfs = [0]

for v in arr:
    pfs.append(v+pfs[-1])

miv = 9999999999999
for k in range(1, n+1):
    left = pfs[k]
    right = pfs[n]-pfs[k]
    if (abs(left-right) < miv):
        miv = abs(left-right)
print(miv)
