// Le Duc Phuc Long, 2024
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define nln '\n'

typedef long long ll;

struct item {
    ll vertex, distance;
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    ll spanningTree(int V, vector<vector<int>> adj[])
    {
        auto cmp = [](const item& it1, const item& it2) {
            return it1.distance > it2.distance;
        };
        priority_queue<item, vector<item>, decltype(cmp)> pq(cmp);
        vector<bool> inMST(V, false);
        vector<ll> parent(V, 0);

        pq.push({0, 0});
        
        vector<vector<ll>> mstEdges;
        ll mstWeight = 0;

        while (!pq.empty()) {
            auto ver = pq.top();
            // "vertext" have minimum "distance" to the current MST
            ll vertex = ver.vertex, distance = ver.distance;
            pq.pop();

            if (inMST[vertex])
                continue;

            // Put this vertex to MST
            inMST[vertex] = 1;
            // Add to the MST total weight
            mstWeight += distance;
            // Add this edge to MST
            mstEdges.push_back({vertex, parent[vertex]});

            // Add the unvisited neightbour of vertex
            for (auto nei : adj[vertex])
                if (!inMST[nei[0]]) {
                    pq.push({nei[0], nei[1]});
                    parent[nei[0]] = vertex;
                }
        }

        if (mstEdges.size() < V)
            return -1;

        // for (auto edge : mstEdges) {
        //     if (edge[0]  != edge[1])
        //         cout << edge[0] << " <-> " << edge[1] << nln;
        // }

        return mstWeight;
    }
};

int main(int argc, char const *argv[]) {
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