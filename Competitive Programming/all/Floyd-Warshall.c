// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define nln '\n'
#define N 100

typedef long long int lo;

// Declare global variables.

struct Edge {
    int src, dest, weight;
};

int V, E;
struct Edge Edges[N];
int dist[N][N], parent[N][N];

bool ok(int x)  {
    return x != INT_MAX;
}

void print() {
    printf("\n");
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j) {
            printf("Khoang cach tu dinh %d den %d la ", i, j); // NOLINT
            if (ok(dist[i][j]))
                printf("%i\n", dist[i][j]);
            else
                printf("Infinity\n");
        }
}

void build_matrix() {
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = INT_MAX, parent[i][j] = i;
    for (int i = 0; i < E; ++i)
        dist[Edges[i].src][Edges[i].dest] = Edges[i].weight;
}

void Floyd_Warshall() {
    for (int i = 0; i < V; ++i)
        for (int u = 0; u < V; ++u)
            for (int v = 0; v < V; ++v)
                    if (ok(dist[u][v]) && (lo)dist[u][i] + (lo)dist[i][v] < (lo)dist[u][v])
                        dist[u][v] = dist[u][i] + dist[i][v], parent[u][v] = parent[i][v];
}

int main(int argc, char* argv[]) {
    V = 5;
    E = 9;

    Edges[0].src = 0;
    Edges[0].dest = 1;
    Edges[0].weight = 1;

    Edges[1].src = 1;
    Edges[1].dest = 2;
    Edges[1].weight = 3;

    Edges[2].src = 2;
    Edges[2].dest = 3;
    Edges[2].weight = 1;

    Edges[3].src = 4;
    Edges[3].dest = 3;
    Edges[3].weight = 4;

    Edges[4].src = 3;
    Edges[4].dest = 2;
    Edges[4].weight = 2;

    Edges[5].src = 0;
    Edges[5].dest = 4;
    Edges[5].weight = 3;

    Edges[6].src = 2;
    Edges[6].dest = 4;
    Edges[6].weight = -5;

    Edges[7].src = 1;
    Edges[7].dest = 4;
    Edges[7].weight = 8;

    Edges[8].src = 1;
    Edges[8].dest = 3;
    Edges[8].weight = 3;

    build_matrix();
    Floyd_Warshall();
    print();

    return 0;
}
