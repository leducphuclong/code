#include <iostream>
#include <string.h>

using namespace std;

#define nln '\n'

const int N = 3e2+5, MOD = 1000000007;
long long dp[N][N*N], pfs[N*N];

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        // Build Prefix Sum
        pfs[0] = dp[i-1][0];
        for (int j = 1; j <= n*k; ++j)
            pfs[j] = pfs[j-1]+dp[i-1][j], pfs[j] %= MOD;
        // Construct dp[i][j]
        for (int j = 1; j <= n*k; ++j)
            dp[i][j] += pfs[j-1] - ((j-k-1 < 0) ? 0 : pfs[j-k-1]) + MOD, dp[i][j] %= MOD;
    }
    long long ans = 0;
    for (int i = p+1; i <= n*k; ++i)
        ans += dp[n][i], ans %= MOD;
    cout << ans << nln;
    return 0;
}
