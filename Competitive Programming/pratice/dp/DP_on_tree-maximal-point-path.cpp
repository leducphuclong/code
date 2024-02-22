// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

class GFG {

public:
    // Adjacency list to store the edges.
    vector<vector<pair<int, int> > > adj;

    // To store maximum points of a path
    // starting at a node
    vector<int> dp;

    // Visited vector to keep trackof nodes for
    // which dp values has already been calculated
    vector<int> vis;

    // To store the final answer
    int ans = 0;

    // Function for visiting every node and
    // calculating dp values for each node.
    void dfs(int curr_node, vector<int>& points)
    {
        vis[curr_node] = true;
        dp[curr_node] = points[curr_node];
        int mx1 = 0, mx2 = 0;
        for (auto v : adj[curr_node]) {
            if (!vis[v.first]) {
                dfs(v.first, points);
                if (dp[v.first] - v.second >= mx1) {
                    mx2 = mx1;
                    mx1 = dp[v.first] - v.second;
                } else if (dp[v.first > mx2]) {
                    mx2 = dp[v.first] - v.second;
                }
            }
        }
        dp[curr_node] += mx1;
        ans = max(ans, mx1+mx2+points[curr_node]); 
        vis[curr_node] = false;
    }

    // To find maximal points path
    int MaxPointPath(int n, vector<int> points,
                    vector<vector<int> > edges)
    {
        adj.resize(n + 1);
        dp.resize(n + 1);
        vis.resize(n + 1, false);

        // Filling adajency list
        for (int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(
                { edges[i][1], edges[i][2] });

            adj[edges[i][1]].push_back(
                { edges[i][0], edges[i][2] });
        }

        // Calling dfs for node 1
        dfs(1, points);

        return ans;
    }
};

// Driver code
int main()
{
    GFG obj;

    // Number of Vertices
    int n = 5;

    // Points at each node
    vector<int> points(n + 1);
    points[1] = 6;
    points[2] = 3;
    points[3] = 2;
    points[4] = 5;
    points[5] = 0;

    // Edges and their lengths
    vector<vector<int> > edges{
        { 1, 2, 10 }, { 2, 3, 3 }, { 2, 4, 1 }, { 1, 5, 11 }
    };

    cout << obj.MaxPointPath(n, points, edges);
    return 0;
}
