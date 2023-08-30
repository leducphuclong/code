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

 public:
    vector<int> circuit;

    explicit Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void AddEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool DFS_find_backedge(int v, bool vst[], bool chk[]) {
        if (chk[v])
            return false;
        vst[v] = 1;
        circuit.push_back(v);
        for (auto nbh : adj[v])
            if (vst[nbh])
                return true;
            else
                if (!chk[nbh] && DFS_find_backedge(nbh, vst, chk))
                    return true;
        circuit.pop_back();
        vst[v] = 0;
        chk[v] = 1;
        return false;
    }

    bool IsCycle() {
        bool vst[V]; memset(vst, 0, sizeof(bool)*V);
        bool chk[V]; memset(chk, 0, sizeof(bool)*V);
        for (int v = 0; v < V; ++v)
            if (DFS_find_backedge(v, vst, chk))
                return true;
        return false;
    }

    void PrintCycle() {
        if (IsCycle()) {
            cout << "This cycle contains circuit: " << nln;
            for (auto v : circuit)
                cout << v << " -> ";
            cout << *circuit.begin() << nln;
        } else {
            cout << "This graph doesn't contain circuit." << nln;
        }
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
    G.PrintCycle();
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
