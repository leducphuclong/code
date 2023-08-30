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
    int *in;

 public:
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

    void AddEdge(int u, int v) {
        adj[u].push_back(v); in[v]++;
    }

    int Is_Eulerian() {
        int sv = 0, fv = 0, dv = 0;
        for (int v = 0; v < V; ++v) {
            if (adj[v].size() != in[v]) {
                ++dv;
                if (adj[v].size() - in[v] == 1)
                    sv++;
                if (in[v] - adj[v].size() == 1)
                    fv++;
            }
        }
        if (dv == 0)  // Eulerian Circuit
            return 2;
        if (dv == 2 && sv == 1 && fv == 1)
            return 1;
        return 0;
    }

    void DFS_FindingTrail(int v, stack<int> &trail) {
        // Hierholzer’s Algorithm
        while (!adj[v].empty()) {
            int tmp = adj[v].back();
            adj[v].pop_back();
            DFS_FindingTrail(tmp, trail);
        }
        trail.push(v);
    }

    void PrintEulerianTrail() {
        int chk = Is_Eulerian();
        if (!chk) {
            cout << "This Graph is not Elerian." << nln;
            return;
        }
        int s = 0;
        if (chk == 2) {
            cout << "This Graph has a Elerian Circuit:" << nln;
        } else {
            cout << "This Graph has a Elerian Path:" << nln;
            for (int v = 0; v < V; ++v)
                if (adj[v].size() - in[v] == 1)
                    s = v;
        }

        stack<int> trail;
        DFS_FindingTrail(s, trail);
        while (trail.size() > 1) {
            cout << trail.top() << " -> ";
            trail.pop();
        }
        cout << trail.top() << nln;
    }
};

int main(int argc, char* argv[]) {
    Graph G1(3);
    G1.AddEdge(0, 1);
    G1.AddEdge(1, 2);
    G1.AddEdge(2, 0);
    G1.PrintEulerianTrail();

    Graph G2(7);
    G2.AddEdge(0, 1);
    G2.AddEdge(0, 6);
    G2.AddEdge(1, 2);
    // G2.AddEdge(2, 0);
    G2.AddEdge(2, 3);
    G2.AddEdge(3, 4);
    G2.AddEdge(4, 2);
    G2.AddEdge(4, 5);
    G2.AddEdge(5, 0);
    G2.AddEdge(6, 4);
    G2.PrintEulerianTrail();

    Graph G3(3);
    G3.AddEdge(0, 1);
    G3.AddEdge(1, 2);
    G3.AddEdge(1, 2);
    G3.PrintEulerianTrail();
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
