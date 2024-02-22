// Include
#include <bits/stdc++.h>
using namespace std;

#define int long long

// Constant
const int N = 105, V = 1005*N;

// Declare global variables.
vector<pair<int, int>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, w, wei[N], val[N];
int dp[V];

void precompute() {
    for (int i = 0; i < V; ++i)
        dp[i] = INT_MAX;
}

void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
        cin >> wei[i] >> val[i];

    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = V - 1; j >= val[i]; --j) {
            if (dp[j - val[i]] != INT_MAX && dp[j] + wei[i] <= w)
                dp[j] = min(dp[j], dp[j - val[i]] + wei[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < V; ++i) {
        if (dp[i] <= w)
            ans = i;
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    precompute();
    while (T--) {
        solve();
    }
    return 0;
}