#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

#define nln '\n'

using namespace std;

int main() {
    freopen("in", "r", stdin);
    int tc;     cin >> tc;
    cin.ignore();
    while (tc--) {
        vector<int> arr;
        string line, tmp;    getline(cin, line, nln);
        stringstream s; s << line;
        while (s >> tmp) {
            stringstream cvt;   cvt << tmp;
            int val;    cvt >> val;
            arr.push_back(val);
        }
        int n = sizeof(arr)/sizeof(int);

        int dp[10];
        memset(dp, 0, sizeof dp);

        for (auto v : arr) {
            vector<bool> mrk(10, false);
            while (v > 0)
                mrk[v%10] = true, v /= 10;
            int mx = 1;
            for (int d = 0; d < 10; ++d)
                if (mrk[d])
                    mx = max(mx, dp[d]+1);
            for (int d = 0; d < 10; ++d)
                if (mrk[d])
                    dp[d] = mx;
        }

        int ans = 0;
        for (int d = 0; d < 10; ++d)
            ans = max(ans, dp[d]);
        cout << ans << nln;
    }
    return 0;
}