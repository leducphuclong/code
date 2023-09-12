tc = int(input())

for _ in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = [arr[0]]
    for i in range(1, n):
        if arr[i] < ans[-1]:
            ans.append(arr[i])
        ans.append(arr[i])
    print(len(ans))
    print(*ans)
            