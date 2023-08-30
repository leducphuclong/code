// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

class Graph {
    int V, vS, vF;
    vector<int> *adj;
    int *prt, *pth;

 public:
    explicit Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
        prt = new int[V];
        pth = new int[V];
        for (int v = 0; v < V; ++v)
            prt[v] = v, pth[v] = v;
    }

    ~Graph() {
        delete[] adj;
        delete[] prt;
    }

    void AddEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void UnionParent(int pu, int pv, int u, int v) {
        prt[pu] = pv;
        pth[u] = v;
    }

    int FindParent(int v) {
        if (prt[v] == v)
            return v;
        return FindParent(prt[v]);
    }

    bool IsCycle() {
        for (int v = 0; v < V; ++v)
            for (auto u : adj[v])
                if (u > v) {
                    int pv = FindParent(v);
                    int pu = FindParent(u);
                    if (pu == pv) {
                        vS = u;
                        vF = v;
                        return true;
                    } else {
                        UnionParent(pu, pv, u, v);
                    }
                }
        return false;
    }

    void PrintReverse(int v, int pv) {
        if (v == pth[v])
            return;
        PrintReverse(pth[v], pv);
        cout << " -> " << v;
    }

    void PrintCycle() {
        if (IsCycle()) {
            cout << "This Graph contains the circuit." << nln;
            int PvS = FindParent(vS), tvS = vS;
            while (vS != PvS) {
                cout << vS << " -> ";
                vS = pth[vS];
            }
            cout << vS;
            PrintReverse(vF, FindParent(vF));
            cout << " -> " << tvS << nln;
        } else {
            cout << "This Graph doesn't contain the circuit." << nln;
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
