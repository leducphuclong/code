//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {

        if (k == 1)
            return true;
        if (k > n)
            return false;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i];
            // cout << a[i] << ' ';
        }
        // cout << endl;
        if (s % k != 0)
            return false;
        int tar = s / k;
        // cout << "tar: " << tar << endl;
        int dp[1<<n];
        memset(dp, -1, sizeof dp);
        dp[0] = 0;

        for (int i = 0; i < (1 << n); ++i) {
            if (dp[i] == -1)    continue;
            for (int j = 0; j < n; ++j)
                if (!(i & (1 << j)) && dp[i]+a[j] <= tar)
                    dp[i^(1 << j)] = (dp[i]+a[j]) % tar;
        }
        return dp[(1 << n) - 1] == 0;
    }
};

//{ Driver Code Starts.
int main()
{
    // freopen("in", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends