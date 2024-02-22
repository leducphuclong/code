// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

/* Theory
    - A directed graph has an eulerian cycle if following
    conditions are true:
        1. All verticles with nonzero degree belong to a single
        strongly connected component.
        2. In degree is equal to the out degree for every vertex.
*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

class Graph {
 public:
    int V;
    list<int> *adj;
    int *in;
    explicit Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        in = new int[V];
        memset(in, 0, sizeof(int)*V);
    }
    ~Graph() {
        delete[] adj;
        delete[] in;
    }
    void Add_Edge(int u, int v) {
        adj[u].push_back(v);
        in[v]++;
    }
    void DFSultil(int v, bool vst[]) {
        vst[v] = true;
        for (auto nbh : adj[v])
            if (!vst[nbh])
                DFSultil(nbh, vst);
    }
    void Become_Transpose_Matrix() {
        list<int> *tmp = new list<int>[V];
        for (int v = 0; v < V; ++v)
            for (auto nbh : adj[v]) {
                tmp[nbh].push_back(v);
                in[nbh]--;
                in[v]++;
            }
         adj = tmp;
    }
    list<int>* Get_Undirected_Adjacencies() {
        list<int> *tmp = new list<int>[V];
        for (int v = 0; v < V; ++v)
            for (auto nbh : adj[v]) {
                tmp[v].push_back(nbh);
                tmp[nbh].push_back(v);
            }
        return tmp;
    }
    bool Is_Single_SCC() {
        bool vst[V];
        memset(vst, false, sizeof(bool)*V);
        int v = V-1;
        while (!adj[v].size() && --v >= 0)
            continue;
        list<int> *bkp = adj;
        adj = Get_Undirected_Adjacencies();
        DFSultil(v, vst);
        adj = bkp;
        for (int v = 0; v < V; ++v)
            if (adj[v].size() > 0 && !vst[v]) {
                return false;
            }

        Become_Transpose_Matrix();

        memset(vst, false, sizeof(vst));
        v = V-1;
        while (!adj[v].size() && --v >= 0)
            continue;
        bkp = adj;
        adj = Get_Undirected_Adjacencies();
        DFSultil(v, vst);
        adj = bkp;
        for (int v = 0; v < V; ++v)
            if (adj[v].size() > 0 && !vst[v]) {
                return false;
            }
        return true;
    }
    int Eulerian() {
        if (!Is_Single_SCC()) {
            return 0;
        }
        int cnt = 0;
        for (int v = 0; v < V; ++v)
            if (in[v] != adj[v].size()) {
                ++cnt;
            }
        if (cnt > 2 || cnt == 1)
            return 0;
        if (cnt == 2)
            return 1;
        return 2;
    }
    void Inform() {
        int ans = Eulerian();
        if (ans == 0)
            cout << "graph is not Eulerian\n";
        else if (ans == 1)
            cout << "graph has a Euler path\n";
        else
            cout << "graph has a Euler cycle\n";
    }
};

int main(int argc, char* argv[]) {
    int V; cin >> V;
    Graph G(V);
    int E; cin >> E;
    while (E--) {
        int u, v;
        cin >> u >> v;
        G.Add_Edge(u, v);
    }
    /*Graph G(7);
    G.Add_Edge(1, 0);
    G.Add_Edge(0, 2);
    G.Add_Edge(2, 1);
    G.Add_Edge(0, 3);
    G.Add_Edge(3, 4);
    G.Add_Edge(4, 0);
    // G.Add_Edge(5, 1);
    // G.Add_Edge(1, 6);
    */
    G.Inform();
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
