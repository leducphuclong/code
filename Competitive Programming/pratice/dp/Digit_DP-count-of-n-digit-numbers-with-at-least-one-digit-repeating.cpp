#include <iostream>
#include <cstring>

using namespace std;

// Global Variables
int n, dp[100][1 << 10][2];
// End Declaration

int calculate(int idx, int mask , bool repeated) {
    if (idx == 0)
        return repeated;
    if (dp[idx][mask][repeated] != -1)
        return dp[idx][mask][repeated];
    int way = 0;
    for (int d = ((idx == 1) ? 1 : 0); d < 10; ++d)
        way += calculate(idx-1, mask | (1 << d), repeated || (mask & (1 << d)));
    return dp[idx][mask][repeated] = way;
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << calculate(n, 0, 0);
    return 0;
}