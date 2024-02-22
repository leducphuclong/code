// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

class Graph {
    int V;
    vector<int> *adj;
    int *in;

 public:
    explicit Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
        in = new int[V];
        memset(in, 0, sizeof(int)*V);
    }

    ~Graph() {
        delete[] adj;
        delete[] in;
    }

    void AddEdge(int u, int v) {
        adj[u].push_back(v);
        in[v]++;
    }

    vector<int> TopoSorting() {
        // Initialize the queue
        queue<int> q;
        for (int v = 0; v < V; ++v) {
            if (!in[v])
                q.push(v);
        }
        // Topological Sorting
        vector<int> res;
        while (!q.empty()) {
            int v = q.front();
            for (auto nbh : adj[v])
                if (!--in[nbh])
                    q.push(nbh);
            q.pop();
            res.push_back(v);
        }
        return res;
    }

    bool IsCycle() {
        vector<int> res = TopoSorting();
        return res.size() != V;
    }
};

int main(int argc, char* argv[]) {
    cerr << "It's ok Long, Good for now !!" << nln;
    int E, V;
    cin >> E >> V;
    Graph G(V);
    while (E--) {
        int u, v;
        cin >> u >> v;
        G.AddEdge(u, v);
    }

    vector<int> topo_order = G.TopoSorting();
    for (auto v : topo_order)
        cout << v << ' ';

    return 0;
}
