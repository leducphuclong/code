#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

class Solution {
public:
    void reConstruct(const string& s1, const string& s2, const vector<vector<int>>& dp, int i, int j, const string& currentLCS, vector<vector<bool>>& mark) {
        if (i == 0 || j == 0) {
            cout << currentLCS << endl;
            return;
        }
        if (mark[i][j]) // If already visited, return
            return;
        if (s1[i-1] == s2[j-1]) {
            mark[i][j] = true;
            reConstruct(s1, s2, dp, i-1, j-1, currentLCS + s1[i-1], mark);
            cout << s1[i-1];
        } else {
            if (dp[i-1][j] == dp[i][j] && !mark[i-1][j]) {
                mark[i-1][j] = true;
                reConstruct(s1, s2, dp, i-1, j, currentLCS, mark);
            }
            if (dp[i][j-1] == dp[i][j] && !mark[i][j-1]) {
                mark[i][j-1] = true;
                reConstruct(s1, s2, dp, i, j-1, currentLCS, mark);
            }
        }
    }

    void memoization(const string& s1, const string& s2, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != -1)
            return;
        if (s1[i-1] == s2[j-1]) {
            memoization(s1, s2, dp, i-1, j-1);
            dp[i][j] = dp[i-1][j-1] + 1;
        } else {
            memoization(s1, s2, dp, i-1, j);
            memoization(s1, s2, dp, i, j-1);
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int longestCommonSubsequence(const string& s1, const string& s2) {
        if (s1.empty() || s2.empty()) {
            // Handle empty strings
            return 0;
        }
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = 0;

        memoization(s1, s2, dp, n, m);

        vector<vector<bool>> mark(n+1, vector<bool>(m+1, false));
        // reConstruct(s1, s2, dp, n, m, "", mark);

        return dp[n][m];
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