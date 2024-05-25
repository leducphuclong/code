// Le Duc Phuc Long, 2024
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define nln '\n'

typedef long long ll;

struct item {
    ll vertex, distance;
    // constructor
    item(ll v, ll d) : vertex(v), distance(d) {}
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

        vector<ll> key(V, INT_MAX);
        vector<ll> parent(V, 0);
        vector<bool> inMST(V, false);

        key[0] = 0;
        pq.push(item(0, key[0]));

        ll mstWeight = 0;
        vector<vector<ll>> mstEdges;

        while (!pq.empty()) {
            ll vertex = pq.top().vertex;
            ll distance = pq.top().distance;
            pq.pop();

            if (inMST[vertex])
                continue;

            inMST[vertex] = true;
            mstWeight += key[vertex];    
            mstEdges.push_back({parent[vertex], vertex});

            for (auto nei : adj[vertex]) {
                ll destVertex = nei[0];
                ll destDistance = nei[1];
                if (!inMST[destVertex] && destDistance < key[destVertex]) {
                    pq.push(item(destVertex, destDistance));
                    key[destVertex] = destDistance;
                    parent[destVertex] = vertex;
                }       
            }
        }

        mstEdges.erase(mstEdges.begin());

        // for (auto edge : mstEdges)
        //     cout << edge[0] << " <-> " << edge[1] << nln;
        
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