//{ Driver Code Starts
#include<bits/stdc++.h>
#include <unistd.h>

using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
            
    }
};

//{ Driver Code Starts.


int main()
{
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends