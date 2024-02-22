//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int find_idx(set<int> s, int &k, int n) {
        if (n == 1)
            return 0;
        n--;
        int fact = n;
        while (n > 1 && k >= fact)
            fact *= (--n);

        int idx = k / fact;

        k %= fact;

        return idx;
    }

    string kthPermutation(int n, int k)
    {
        set<int> s;
        for (int i = 1; i <= n; ++i)
            s.insert(i);
        string res = "";
        k--;
        for (int i = 0; i < n; ++i) {
            int idx = find_idx(s, k, n-i);
            auto itr = s.begin();
            advance(itr, idx);
            res += to_string(*itr);
            s.erase(itr);
        } 
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    freopen("in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);

        cout << ans;
        cout << "\n";
    }
    cerr << "OK" << endl;
    return 0;
}

// } Driver Code Ends