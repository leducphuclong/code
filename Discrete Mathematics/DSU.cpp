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
    list<int> *adj;
    int *parent;
 public:
    explicit Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        parent = new int[V];
        for (int v = 0; v < V; ++v)
            parent[v] = v;
    }
    ~Graph() {
        delete[] adj;
        delete[] parent;
    }
    void AddEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int Find_Subset(int v) {
        if (parent[v] == v)
            return v;
        return Find_Subset(parent[v]);
    }
    void Union(int u, int v) {
        parent[u] = v;
    }
    bool IsCycle() {
        for (int v = 0; v < V; ++v)
            for (auto nbh : adj[v])
                if (v > nbh) {
                    int Pv = Find_Subset(v);
                    int Pnbh = Find_Subset(nbh);
                    if (Pv == Pnbh)
                        return true;
                    Union(v, nbh);
                }
        return false;
    }
};

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    int V, E;
    cin >> V >> E;
    Graph G(V);
    while (E--) {
        int u, v;
        cin >> u >> v;
        G.AddEdge(u, v);
    }
    if (G.IsCycle())
        cout << "Graph contains cycle." << nln;
    else
        cout << "Graph doesn't contain cycle." << nln;
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
