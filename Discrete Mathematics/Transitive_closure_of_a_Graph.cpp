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
    void DFSUtil(int u, int v);
 public:
    bool** mtx;
    bool** tc;
    explicit Graph(int V);
    ~Graph();
    void build_matrix();
    vector<vector<int>> TransitiveClosure();
};

Graph::Graph(int V) {
    this->V = V;
    mtx = new bool*[V];
    tc = new bool*[V];
    for (int i = 0; i < V; ++i) {
        mtx[i] = new bool[V];
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}

Graph::~Graph() {
    for (int i = 0; i < V; ++i)
        delete[] tc[i], delete[] mtx[i];
    delete[] tc;
    delete[] mtx;
}

void Graph::build_matrix() {
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> mtx[i][j];
}

void Graph::DFSUtil(int u, int v) {
    tc[u][v] = 1;
    for (int i = 0; i < V; ++i)
        if (mtx[v][i] && !tc[u][i]) {
            if (i == u)
                tc[u][i] = 1;
            else
                DFSUtil(u, i);
        }
}

vector<vector<int>> Graph::TransitiveClosure() {
    for (int s = 0; s < V; ++s)
        if (!tc[s][s])
            DFSUtil(s, s);
    // Output
    vector<vector<int>> out;
    for (int i = 0; i < V; ++i) {
        out.push_back({});
        for (int j = 0; j < V; ++j)
            out[i].push_back(tc[i][j]);
    }
    return out;
}

int main(int argc, char* argv[]) {
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        int V;
        cin >> V;
        Graph G(V);
        G.build_matrix();
        vector<vector<int>> out = G.TransitiveClosure();
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j)
                cout << out[i][j] << ' ';
            cout << nln;
        }
    }
    cout << "Good for now !!" << nln;
    return 0;
}
