n, x, q = map(int, input().split())
arr = list(map(int, input().split()))

# Build prefix sum
s = [0]
for v in arr:
    s.append(v+s[-1])

# Solve
dem = 0
for i in range(q):
    l, r = map(int, input().split())
    t = s[r]-s[l-1]
    if (t < x):
        dem += 1

print(dem)
