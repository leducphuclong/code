tc = int(input())

for _ in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        if i+1 == arr[i]:
            ans += 1
    print(ans//2 + ans%2)