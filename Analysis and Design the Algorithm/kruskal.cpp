// Le Duc Phuc Long, 2024
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define nln '\n'
typedef long long ll;

class dsu {
private:
	ll n, *parent, *rank;
public:
	dsu(ll size);
	~dsu();	
	ll find(ll);
	void unite(ll, ll);
	bool connected(ll, ll);
};

dsu::dsu(ll size) : n(size) {
	parent = new ll[n];
    rank = new ll[n];
	for (ll v = 0; v < n; ++v)
		parent[v] = v,
        rank[v] = 0;
}

dsu::~dsu() {
	delete[] parent;
}

ll dsu::find(ll index) {
    // find and compress simultaneously
    ll tmp = index;
	while (index != parent[index])
		index = parent[index];

    ll representative = index;
    index = tmp;
    while (index != representative) {
        tmp = index;
        index = parent[index];
        parent[tmp] = representative;
    }

    return representative;
}

void dsu::unite(ll v, ll u) {
    // unite by rank
	ll parent_v = find(v);
	ll parent_u = find(u);
	if (rank[parent_u] >= rank[parent_v]) {
        parent[parent_v] = parent_u;
        if (rank[parent_u] == rank[parent_v])
            rank[parent_u]++;
    } else {
        parent[parent_u] = parent_v;
    }
}

bool dsu::connected(ll v, ll u) {
	return find(v) == find(u);
}

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {	
    	dsu DSU(V);
    	vector<vector<ll>> edges;
    	for (int v = 0; v < V; ++v) {
    		for (auto nei : adj[v])
    			edges.push_back({v, nei[0], nei[1]});
    	}

    	sort(edges.begin(), edges.end(), [](vector<ll> &e1, vector<ll> &e2) {
    		return e1[2] < e2[2];
    	});

    	ll wei = 0;
    	for (auto edge : edges) {
    		if (DSU.connected(edge[0], edge[1]) == false) {
    			wei += edge[2];
    			DSU.unite(edge[0], edge[1]);
    		}
    	}

  		return wei;
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