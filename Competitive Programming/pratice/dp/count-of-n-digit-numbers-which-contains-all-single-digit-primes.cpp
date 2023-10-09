#include <iostream>
#include <cstring>
#include <map>

using namespace std;

// Global variables
int n, dp[1000][1 << 4], prm[] = {2, 3, 5, 7};
map<int, int> pos;
// End Declaration

int compute(int idx, int mask) {
    if (n == 1)
        return 4;
    if (idx == n+1) {
        if (mask == (1 << 4)-1)
            return 1;
        else
            return 0;
    }
    if (dp[idx][mask] != -1)
        return dp[idx][mask];
    int way = 0;
    for (int d = (idx == 1) ? 1 : 0; d < 10; ++d) {
        if (pos[d])
            way += compute(idx+1, mask | (1 << (pos[d]-1)));
        else
            way += compute(idx+1, mask);
    }
    return dp[idx][mask] = way;
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 4; ++i)
        pos[prm[i]] = i+1;
    cout << compute(1, 0) << endl;
    return 0;
}