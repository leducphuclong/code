#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        if (n < m) {
            swap(n, m);
            swap(s1, s2);
        }

        vector<int> dp(m+1, 0), pv(m+1, 0);

        // Fill the dp table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[j] = pv[j-1] + 1;
                } else {
                    dp[j] = max(pv[j], dp[j-1]);
                }
            }
            pv = dp;
        }

        // Return the length of the LCS
        return pv[m];
    }
};

int main() {
    // Opening input file
    if (access("in", F_OK) != -1) {
        FILE *file = freopen("in", "r", stdin);
        if (file == NULL) {
            perror("Error opening file!");
            return 1;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << "Length of LCS: " << ob.longestCommonSubsequence(s1, s2) << endl;
    }
    return 0;
}
