// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

class Graph {
    #define nln '\n'

    enum colors {White, Grey, Black};
    int V;
    vector<int> *adj;

 public:
    vector<int> circuit;

    explicit Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    ~Graph() {
        delete [] adj;
    }

    void AddEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool DFS_coloring(int v, colors mark[]) {
        if (mark[v] == Black)
            return false;
        mark[v] = Grey;
        circuit.push_back(v);
        for (auto nbh : adj[v])
            if (mark[nbh] == Grey)
                return true;
            else
                if (mark[nbh] == White && DFS_coloring(nbh, mark) == true)
                    return true;
        circuit.pop_back();
        mark[v] = Black;
        return false;
    }

    void IsCycle() {
        colors mark[V];
        memset(mark, White, sizeof(colors)*V);
        for (int v = 0; v < V; ++v)
            if (mark[v] == White && DFS_coloring(v, mark)) {
                cout << "This Graph contains circuit: " << nln;
                for (auto v : circuit)
                    cout << v << " -> ";
                cout << *circuit.begin() << nln;
                return;
            }
        cout << "This Graph doesn't contain circuit." << nln;
    }
};

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    int V;      cin >> V;

    Graph G(V);
    int E;      cin >> E;
    while (E--) {
        int u, v;
        cin >> u >> v;
        G.AddEdge(u, v);
    }
    G.IsCycle();
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
