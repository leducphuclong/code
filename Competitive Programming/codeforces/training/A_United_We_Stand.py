tc = int(input())

for _ in range(tc):
    # Input
    n = int(input())
    arr = list(map(int, input().split()))
    # Solve
    miv = min(arr)
    c, d = [], []
    for v in arr:
        if v == miv:
            c.append(v)
        else:
            d.append(v)
    if (len(c) == n):
        print(-1)
        continue
    print(len(c), len(d))
    print(*c)
    print(*d)