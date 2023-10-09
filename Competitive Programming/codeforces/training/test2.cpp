//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    // function to find totient of n
    long long ETF(long long n){
        long long cnt = n;
        for (long long i = 2; i*i <= n; ++i) {
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                cnt -= cnt/i;
            }
        }
        if (n > 1)
            cnt -= cnt/n;
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t = 1;
    // cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout << ob.ETF(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends