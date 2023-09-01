// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.
enum Color {WHITE, GRAY, BLACK};

class Graph {
    lo V;  // No. of verticles
    list<lo>* adj;  // a list<int> poiter of the
    // first adjacency list of a list of adjacency lists
    bool DFSUtil(lo v, lo color[]);
 public:
    explicit Graph(lo V);  // Constructor
    void addEdge(lo u, lo v);
    bool isCyclic();
};

Graph::Graph(lo V) {
    this -> V = V;
    adj = new list<lo> [V];
}

// Utility function to add an edge
void Graph::addEdge(lo u, lo v) {
    adj[u].push_back(v);
}

bool Graph::DFSUtil(lo u, lo color[]) {
    color[u] = GRAY;
    list<lo>::iterator v;
    for (v = adj[u].begin(); v != adj[u].end(); ++v) {
        if (color[*v] == GRAY)
            return 1;
        if (color[*v] == WHITE && DFSUtil(*v, color))
            return true;
    }
    color[u] = BLACK;
    return false;
}

bool Graph::isCyclic() {
    lo *color = new lo[V];
    for (lo v = 0; v < V; ++v)
        color[v] = WHITE;
    for (lo v = 0; v < V; ++v)
        if (color[v] == WHITE &&  DFSUtil(v, color))
            return true;
    return false;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

    return 0;
}
