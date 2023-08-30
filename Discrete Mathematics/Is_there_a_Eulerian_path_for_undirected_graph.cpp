// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

/*  The theory of this lesson
    A graph has Eulerian Path only if:
        - There are exactly two or zero vertice(s) with odd degrees.
        - All vertices with non-zero degree are connected.
    A graph has Eulerian Circuit only if:
        - All vertices have even degree.
        - All vertices with non-zero degree are connected.

    Note:
        - Note that a graph with no edges is also considered Eulerian
        because there are no edges to traverse.

    Definition:
        - Utility functions are generally small, reusable code modules that are 
        designed to perform a specific task or set of tasks that arecommonly needed
        in a program. 
*/

// #include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>

using namespace std;  // NOLINT

#define nln '\n'

// Declare global variables.

class Graph {
    int V;  // No. of verticles
 public:
    list<int> *adj;  // A dynamic array of adjacency lists
    // Constructor and Destructor
    // Hàm tạo và hàm hủy
    explicit Graph(int V) {
        this->V = V;
        this->adj = new list<int>[V];
    }
    ~Graph() {
        delete [] adj;  // Avoid memory leak
    }

    void AddEdge(int u, int v);

    int IsEulerian();

    bool IsConnected();

    void DFSUtil(int u, bool vst[]);
};

void output(Graph &G);  // NOLINT

int main(int argc, char* argv[]) {
    // Input
    freopen("in", "r", stdin);
    int V, E;
    scanf("%i%i", &V, &E);
    Graph G(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        scanf("%i%i", &u, &v);
        G.AddEdge(u, v);
    }
    // Output
    output(G);
    printf("Good for now \n");
    return 0;
}

void output(Graph &G) {  // NOLINT
    int res = G.IsEulerian();
    if (res == 0)
        printf("Graph is not Eulerian\n");
    else if (res == 1)
        printf("Graph has a Euler Path\n");
    else
        printf("Graph has a Euler Circuit\n");
}

void Graph::AddEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFSUtil(int u, bool vst[]) {
    vst[u] = true;
    for (int v : adj[u])
        if (!vst[v])
            DFSUtil(v, vst);
}

bool Graph::IsConnected() {
    bool vst[V];
    // Mark all the vertices as not visited
    for (int i = 0; i < V; ++i)
        vst[i] = false;
    // Find a vertex with non-zero degree
    int u;
    for (u = 0; u < V; ++u)
        if (adj[u].size() != 0)
            break;
    if (u == V)
        return true;
    // If there are no edges in the graph, return true
    // (This is a convention, do not find why)
    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(u, vst);
    // Check if all non-zero degree vertices are visited
    for (int v = 0; v < V; ++v)
        if (vst[v] == false && adj[v].size() > 0) {
            return false;
        }
    return true;
}

int Graph::IsEulerian() {
    if (!IsConnected()) {
        return 0;
    }
    int no_of_odd_vertices = 0;
    for (int v = 0; v < V; ++v)
        if (adj[v].size() % 2)
            no_of_odd_vertices++;
    if (no_of_odd_vertices > 2)
        return 0;
    if (no_of_odd_vertices == 2)
        return 1;
    return 2;
}
