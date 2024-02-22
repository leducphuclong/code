// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

int Current_Minimum_Distance(int V, vector<int> dst, bool spt[]) {
    int miv = INT_MAX, idx = -1;
    for (int v = 0; v < V; ++v)
        if (!spt[v] && dst[v] < miv)
            miv = dst[v], idx = v;
    return idx;
}  // Tìm điểm gần nhất 

int main(int argc, char* argv[]) {
    // Input
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V];
    while (E--) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    int s; cin >> s;
    vector<int> dst(V, INT_MAX); dst[s] = 0; //Nhập cạnh
    // Dijkstra's Algorithm
    bool spt[V];  // Shortest Path Tree
    memset(spt, false, sizeof(bool)*V);
    for (int tms = 0; tms < V-1; ++tms) {
        int v = Current_Minimum_Distance(V, dst, spt);
        spt[v] = true;
        for (auto nbh : adj[v])
            if (dst[nbh.first] > dst[v] + nbh.second)
                dst[nbh.first] = dst[v] + nbh.second;
    }
    for (int v = 0; v < V; ++v)
        cout << dst[v] << ' ';
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
