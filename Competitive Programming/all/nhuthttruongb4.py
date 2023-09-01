import sys

sys.stdin = open("tauthoat.inp", "r")
sys.stdout = open("tauthoat.out", "w")

n, t = map(int, input().split())
arr = list(map(int, input().split()))

dp = [0]
MAX = 99999999900

for i in range(1, n):
    dp.append(MAX)
    for j in range(i):
        dp[i] = min(dp[i], dp[j]+(i-j)*abs(arr[i]-arr[j]))

if (dp[n-1] <= t):
    print("YES")
    print(dp[n-1])
else:
    print("NO")
