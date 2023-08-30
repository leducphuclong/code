//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        reverse(arr.begin(), arr.end());
        stack<long long> tower;
        vector<long long> res;
        tower.push(arr.back());
        arr.pop_back();
        while (!arr.empty()) {
            cout << "back: " << arr.back() << endl;
            cout << "top: " << tower.top() << endl;
            if (tower.empty()) {
                cout << "hi" << endl;
                res.push_back(-1);
            }
            while (!tower.empty() && arr.back() > tower.top()) {
                res.push_back(arr.back());
                tower.pop();
            }
            tower.push(arr.back());
            arr.pop_back();
            cout << endl;
        }
        while (!tower.empty()) {
            res.push_back(-1);

            tower.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends