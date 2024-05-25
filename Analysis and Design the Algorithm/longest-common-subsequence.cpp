#include <bits/stdc++.h>
#include <unistd.h>


using namespace std;

class Solution{
public:
    void reConstruct(string s1, string s2, vector<vector<int>>& dp, int i, int j, string currentLCS, vector<vector<bool>>& mark) {
        // Base case: if we've reached the start of either string
        if (mark[i][j])
            return;
        if (i == 0 || j == 0) {
            // Print the current LCS
            reverse(currentLCS.begin(), currentLCS.end()); // Reverse the output string
            cout << currentLCS << endl;
            return;
        }
        // If characters match, include this character in LCS
        if (s1[i-1] == s2[j-1]) {
            mark[i][j] = true; // Mark the current position
            reConstruct(s1, s2, dp, i-1, j-1, currentLCS + s1[i-1], mark); // Recursive call
            // Output the character after the recursive call to ensure correct order
            cout << s1[i-1];
        } else {
            // If they don't match, find which direction to move
            if (dp[i-1][j] == dp[i][j]) {
                mark[i-1][j] = true; // Mark the current position
                reConstruct(s1, s2, dp, i-1, j, currentLCS, mark); // Recursive call
            }
            if (dp[i][j-1] == dp[i][j]) {
                mark[i][j-1] = true; // Mark the current position
                reConstruct(s1, s2, dp, i, j-1, currentLCS, mark); // Recursive call
            }
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Fill the dp table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // Reconstruct and print all LCSs
        // vector<vector<bool>> mark(n+1, vector<bool>(m+1, false));
        // reConstruct(s1, s2, dp, n, m, "", mark);

        // Return the length of the LCS
        return dp[n][m];
    }
};

int main(){
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
    while(t--){
        string s1, s2;    
        cin >> s1 >> s2;
        
        Solution ob;
        cout << "Length of LCS: " << ob.longestCommonSubsequence(s1, s2) << endl;
    }
    return 0;
}
