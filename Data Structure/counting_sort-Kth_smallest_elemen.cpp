//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#define nln '\n'

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int n = r-l+1, miv = INT_MAX;
    
        map<int, int> cnt;
        for (int i = l; i <= r; ++i) {
            cnt[arr[i]]++;
            if (arr[i] < miv)
                miv = arr[i];
        }
        
        int idx = miv;
        vector<int> res;
        while (n > 0) {
            if (cnt[idx] == 0)
                ++idx;
            else {
                res.push_back(idx);
                cnt[idx]--;
                n--;
            }
        }

        return res[k-1];
    }
};


//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends