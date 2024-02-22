tc = int(input())
for _ in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    cnt = 0
    for v in arr:
        if v % 2 == 1:
            cnt += 1
    if (cnt % 2) == 0:
        print("YES")
    else:
        print("NO")