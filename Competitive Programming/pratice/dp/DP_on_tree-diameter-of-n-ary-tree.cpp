// C++ program to find diameter of a tree
// using DFS.
#include <bits/stdc++.h>
using namespace std;

// Function to find the diameter of the tree
// using Dynamic Programming

int ans = 0;

void diameter(int u, int p, int dp1[], int dp2[], list<int>* adj) {
    int mx1 = 0, mx2 = 0;
    for (auto v : adj[u]) {
        if (v == p)
            continue;
        diameter(v, u, dp1, dp2, adj);
        int d = dp1[v];
        if (d >= mx1) {
            mx2 = mx1, mx1 = d;
        } else if (d > mx2) {
            mx2 = d;
        }
    }
    dp1[u] = mx1+1;
    dp2[u] = mx1+mx2+1;
    ans = max(ans, max(dp1[u], dp2[u]));
}

// Driver Code
int main()
{
    int n = 8;

    /* Constructed tree is 
        1 
        / \ 
        2 3 
    / \ 
    4 5 */
    list<int>* adj = new list<int>[n + 1];

    /*create undirected edges */
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    adj[5].push_back(2);
    adj[5].push_back(6);
    adj[6].push_back(5);
    adj[5].push_back(7);
    adj[7].push_back(5);
    adj[7].push_back(8);
    adj[8].push_back(7);

    int dp1[n + 1], dp2[n + 1];
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);

    diameter(1, 0, dp1, dp2, adj);
    // Find diameter by calling function
    cout << "Diameter of the given tree is "
        << ans << endl;

    return 0;
}
