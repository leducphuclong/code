// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

void BellmanFord(int mtx[][N], int n, int src) {
    int dist[n];
    for (int i = 0; i < n; ++i)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int tms = 1; tms <= n-1; ++tms) {
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                if (dist[u] != INT_MAX && mtx[u][v] && (dist[v] == INT_MAX || dist[v] > dist[u] + mtx[u][v]))
                    dist[v] = dist[u] + mtx[u][v];
    }
    for (int v = 0; v < n; ++v)
        printf("Duong di ngan nhat tu dinh %i den dinh %i: %i\n", src, v, dist[v]);
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    int mtx[N][N], n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++j)
            scanf("%i", &mtx[i][j]);
    BellmanFord(mtx, n, 0);
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
