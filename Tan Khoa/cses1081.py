N = int(1e6) + 10

cnt = [0]*N

n = int(input())
arr = list(map(int, input().split()))

for v in arr:
    cnt[v] += 1


ans = 1
d = 2
while d < N:
    i = d
    t = 0
    while (i < N):
        t += cnt[i]
        i += d
    if (t >= 2):
        ans = max(ans, d)
    d += 1

print(ans)

    





