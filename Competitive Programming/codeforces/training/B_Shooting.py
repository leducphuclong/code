import sys

input = sys.stdin.readline

MOD = 1000000007 

n, k, p = map(int, input().split())

dp = [[0 for __ in range(n*k+1)] for _ in range(n+1)]

dp[0][0] = 1

for i in range(1, n+1):     
    pfs = [0]*(n*k+1)
    pfs[0] = dp[i-1][0]
    for j in range(1, k*n+1):
        pfs[j] = pfs[j-1] + dp[i-1][j]
        pfs[j] %= MOD
    for j in range(1, n*k+1):
        dp[i][j] += pfs[j-1]
        # dp[i][j] -= pfs[max(0, j-k-1)]
        if j-k-1 >= 0:
            dp[i][j] -= pfs[j-k-1]
        dp[i][j] += MOD; dp[i][j] %= MOD

ans = 0
for i in range(p+1, n*k+1):
    ans += dp[n][i]; ans %= MOD
    
print(ans%MOD)
