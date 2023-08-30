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
    void Add_Edge(int u, int v);
    explicit Graph(int V);
    ~Graph();
    void FillOrder(int v, bool vst[], stack<int> &ord);
    void DFSUtil(int v, bool vst[], list<int> trm[]);
    void Get_Transpose_Matrix(list<int> trm[]);
    int Number_of_the_SCCs();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::Add_Edge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::FillOrder(int v, bool vst[], stack<int> &ord) {
    vst[v] = true;
    for (auto u : adj[v])
        if (!vst[u])
            FillOrder(u, vst, ord);
    ord.push(v);
}

void Graph::Get_Transpose_Matrix(list<int> trm[]) {
    for (int v = 0; v < V; ++v)
        for (auto nei : adj[v])
            trm[nei].push_back(v);
}

void Graph::DFSUtil(int v, bool vst[], list<int> trm[]) {
    vst[v] = true;
    for (auto nbh : trm[v])
        if (!vst[nbh])
            DFSUtil(nbh, vst, trm);
}

int Graph::Number_of_the_SCCs() {
    // Find the Order
    stack<int> ord;
    bool vst[V];
    memset(vst, false, sizeof(vst));
    for (int v = 0; v < V; ++v)
        if (!vst[v])
            FillOrder(v, vst, ord);
    // Find the SCCs
    memset(vst, false, sizeof(vst));

    list<int> trm[V];
    Get_Transpose_Matrix(trm);

    int cnt = 0;
    while (!ord.empty()) {
        if (!vst[ord.top()]) {
            ++cnt;
            DFSUtil(ord.top(), vst, trm);
        }
        ord.pop();
    }
    return cnt;
}

void solve() {
    // Input
    int V; cin >> V;
    Graph G(V);

    int E; cin >> E;
    while (E--) {
        int u, v;
        cin >> u >> v;
        G.Add_Edge(u, v);
    }

    // Output
    cout << G.Number_of_the_SCCs() << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    cout << "Good for now !!" << nln;
    return 0;
}
