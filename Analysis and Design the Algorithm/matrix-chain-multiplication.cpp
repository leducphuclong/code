// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

/*  Problem Statement:
Give a sequence of matrices, find the most efficient way to multiply these
matrices together. The efficient way is the one that involves the least number
of multiplications.
*/

/* Approach:
We will using dynamic programming technique to solve this.

4 step:
Step 1:  Characterize the structure of an optimal solution
In this problem, we are give a sequence of matrices to multiply. To find
the optimal way to parenthesize the product of these matrices, we need
to consider the optimal parenthesization of subproblems within the sequence

Step 2:  Recursively define the value of an optimal solution
Let M[i, j] represent the minimum number of scalar multiplications needed to
compute the product of matrices from Ai to Aj, inclusive. To calculate the 
M[i, j] we need to find a 'k' that:
M[i, j] = M[i, k] + M[k+1, j] + cost-of-multiplication
The trivially case is i == j:
We have M[i, j] = 0 (When only 1 matrix left, we don't multiply anymore)

Step 3:  Compute the value of an optimal solution in a bottom-up fashion
We can compute M[i, j] == 0 for all i, j which i == j
That mean we already calculated all the subsequence have length 1.
Now we will continue do it with bottom-up fashion to calculate lenght 2, 3, 4...

Step 4:  Construct an optimal solution from computed information
Once we have all the values of M[i, j], we can reconstruct of the optimal
parenthesization by backtracking through the computed information. This
involdes keeping track of the optimal split locations (k) that were used 
to devide each problem M[i, j].
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

typedef vector<vector<int>> matrix;

class Solution{
    static const int LIM = 100;
    public:
    matrix actuallyMultiply(vector<matrix> A, vector<vector<int>>& ct, int i, int j) {
        if (i == j)
            return A[i];
        
    }

    int Trace(int arr[], vector<vector<int>>& ct, int i, int j) {
        if (j == i) 
            return 0;
        return Trace(arr, ct, i, ct[i][j]) 
        + Trace(arr, ct, ct[i][j]+1, j) + arr[i-1]*arr[ct[i][j]]*arr[j];
    }

    void reConstruct(vector<vector<int>>& ct, int i, int j) {
        if (i == j) {
            cout << "A[" << i << "]";
            return;
        }
        cout << "(";
        reConstruct(ct, i, ct[i][j]);
        reConstruct(ct, ct[i][j]+1, j);
        cout << ")";
    }

    int matrixMultiplication(int N, int arr[])
    {
        int ans = 0, dp[N][N];
        vector<vector<int>> ct(N, vector<int>(N));
        for (int i = 1; i < N; ++i)
            for (int j = 1; j < N; ++j)
                if (i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = INT_MAX;

        for (int l = 2; l <= N; ++l)
            for (int i = 1; i < N-l+1; ++i) {
                int j = i + l - 1;
                for (int k = i; k < j; ++k) {
                    int cal = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    if (dp[i][j] > cal) {
                        dp[i][j] = cal;
                        ct[i][j] = k;
                    }
                }
            }
        // Contruct the optimal solution (Check the answer)
        if (Trace(arr, ct, 1, N-1) != dp[1][N-1])
            return -1;

        // reConstruct(ct, 1, N-1);

        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

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
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends