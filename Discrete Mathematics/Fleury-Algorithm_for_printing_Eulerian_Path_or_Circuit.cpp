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

 public:
    explicit Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void AddEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int DFS_Count(int v, bool vst[]) {
        vst[v] = true;
        int res = 0;
        for (auto nbh : adj[v])
            if (nbh != -1 && !vst[nbh])
                res += DFS_Count(nbh, vst)+1;
        return res;
    }

    void RemoveEdge(int u, int v) {
        auto iv = find(adj[u].begin(), adj[u].end(), v);
        *iv = -1;
        auto iu = find(adj[v].begin(), adj[v].end(), u);
        *iu = -1;
    }

    void DFS_Traversal(int v, bool vst[]) {
        vst[v] = true;
        for (auto nbh : adj[v])
            if (!vst[nbh])
                DFS_Traversal(nbh, vst);
    }

    bool IsConnected() {
        bool vst[V]; memset(vst, false, sizeof(bool)*V);
        int v = V-1;
        while (!adj[v].size() && --v >= 0)
            continue;
        DFS_Traversal(v, vst);
        for (int v = 0; v < V; ++v)
            if (adj[v].size() && !vst[v])
                return false;
        return true;
    }

    int IsThere_A_EulerianPathForUndirectedGraph() {
        if (!IsConnected())
            return 0;
        int cnt = 0;
        for (int v = 0; v < V; ++v)
            if (adj[v].size() % 2)
                ++cnt;
        if (cnt == 1 || cnt > 2)
            return 0;
        if (cnt == 2)
            return 1;
        return 2;
    }

    bool IsBridge(int u, int v) {
        bool vst[V];
        memset(vst, false, sizeof(bool)*V);
        int cnt = DFS_Count(u, vst);

        RemoveEdge(u, v);

        memset(vst, false, sizeof(bool)*V);
        bool chk = (DFS_Count(u, vst) != cnt);

        AddEdge(u, v);

        return chk;
    }

    void DFS_Find_Trail(int u) {
        auto i = adj[u].begin();
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = *i;
            if (v != -1 && !IsBridge(u, v)) {
                cout << u << " ~ " << v << nln;
                RemoveEdge(u, v);
                DFS_Find_Trail(u);
            }
        }
    }

    void Elerian_Path() {
        int u = 0;
        for (int v = 0; v < V; ++v)
            if (adj[v].size() & 1) {
                u = v;
                break;
            }
        DFS_Find_Trail(u);
    }

    void Elerian_Circuit() {
    }

    void PrintEulerTrail() {
        int chk = IsThere_A_EulerianPathForUndirectedGraph();
        switch (chk) {
        case 0:
            cout << "This Graph is not Eulerian." << nln;
            break;
        case 1:
            cout << "This Graph has a Elerian Path: " << nln;
            Elerian_Path();
            break;
        case 2:
            cout << "This Graph has a Elerian circuit: " << nln;
            Elerian_Circuit();
        }
    }
};

int main(int argc, char* argv[]) {
    Graph g1(4);
    g1.AddEdge(0, 1);
    g1.AddEdge(0, 2);
    g1.AddEdge(1, 2);
    g1.AddEdge(2, 3);
    g1.PrintEulerTrail();
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
