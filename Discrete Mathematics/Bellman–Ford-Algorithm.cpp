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
    list<pair<int, int>> *adj;
 public:
    explicit Graph(int V) {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }
    ~Graph() {
        delete[] adj;
    }
    void AddEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void Bellman_Ford(int src, int path[]) {
        for (int v = 0; v < V; ++v)
            path[v] = INT_MAX;
        path[src] = 0;
        for (int tms = 0; tms < V-1; ++tms) {
            for (int v = 0; v < V; ++v)
                if (path[v] != INT_MAX)
                    for (auto nbh : adj[v])
                        if (path[nbh.first] > path[v]+nbh.second)
                            path[nbh.first] = path[v]+nbh.second;
        }
    }

    void PrintTheShortestPathsFrom(int src) {
        int path[V];
        Bellman_Ford(src, path);
        cout << "The shortest distance from " << src << " to: " << nln;
        for (int v = 0; v < V; ++v)
            cout << "-> " << v << ": " << path[v] << nln;
    }
};

int main(int argc, char* argv[]) {
    Graph G(5);
    G.AddEdge(0, 1, -1);
    G.AddEdge(0, 2 , 4);
    G.AddEdge(1, 2, 3);
    G.AddEdge(1, 3, 2);
    G.AddEdge(1, 4, 2);
    G.AddEdge(3, 2, 5);
    G.AddEdge(3, 1, 1);
    G.AddEdge(4, 3, -3);
    G.PrintTheShortestPathsFrom(0);
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
