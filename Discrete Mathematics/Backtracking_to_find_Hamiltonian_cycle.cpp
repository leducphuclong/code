// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

const int V = 5;

// Declare global variables.

bool IsOK(int v, int u, bool graph[][V], bool pick[]) {
    if (!graph[u][v] || pick[v])
        return false;
    return true;
}

bool DFS2Find_Hamiltonian_Cycle(int v, list<int> &path, bool graph[][V], bool pick[]) {
    if (path.size() == V) {
        if (graph[v][*path.begin()])
            return true;
        else
            return false;
    }
    for (int u = 0; u < V; ++u)
        if (IsOK(u, path.back(), graph, pick)) {
            pick[u] = 1;
            path.push_back(u);
            if (DFS2Find_Hamiltonian_Cycle(u, path, graph, pick))
                return true;
            path.pop_back();
            pick[u] = 0;
        }
    return false;
}

void Print_Hamiltonian_Cycle(bool graph[][V]) {
    list<int> path = {0};
    bool pick[V]; memset(pick, false, sizeof(bool)*V);
    pick[0] = true;
    if (DFS2Find_Hamiltonian_Cycle(0, path, graph, pick)) {
        cout << "This graph has the Hamiltonian cycle: " << nln;
        for (auto v : path)
            cout << v << " -> ";
        cout << 0 << nln;
    } else {
        cout << "This graph has not the Hamiltonian cycle. " << nln;
    }
}

int main(int argc, char* argv[]) {
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
    Print_Hamiltonian_Cycle(graph1);

    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
    Print_Hamiltonian_Cycle(graph2);     

    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
