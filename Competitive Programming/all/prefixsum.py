n = int(input())
a = list(map(int, input().split()))
u, v = map(int, input().split())
l, r = map(int, input().split())

pfs = [0]*(n+1)
pfs[0] = 0
for i in range(1, n+1):
    pfs[i] = pfs[i-1] + a[i-1]

print(pfs[v]-pfs[u-1])
print(pfs[r]-pfs[l-1])
