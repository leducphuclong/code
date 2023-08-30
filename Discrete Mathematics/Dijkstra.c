// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

/*
Các đỉnh A, B, C, ..., G được quy ước tương ứng với các đỉnh 0, 1, 2, ...6
Vậy yêu cầu của bài này sẽ là tìm đường đi ngắn nhất từ đỉnh 0 đến đỉnh 6
*/

// Include
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

void Dijkstra(int n, int mtx[][N], int src) {
    int dist[n];
    for (int i = 0; i < n; ++i)
        dist[i] = INT_MAX;
    dist[src] = 0;
    bool spt[n];  memset(spt, false, sizeof(bool)*n);  // 
    int path[n];
    for (int i = 0; i < n; ++i)
        path[i] = i;
    printf("Buoc thu 1:\n");
    for (int i = 0; i < n; ++i) {
        printf("dist[%i] = ",i);
        if (dist[i] == INT_MAX)
            printf("INF | ");
        else
            printf("%i | ", dist[i]);
    }
    printf("\n");
    for (int tms = 0; tms < n-1; ++tms) {
        printf("Buoc thu %i:\n", tms+2);
        for (int i = 0; i < n; ++i) {
            printf("dist[%i] = ",i);
            if (dist[i] == INT_MAX)
                printf("INF | ");
            else
                printf("%i | ", dist[i]);
        }
        //  Tìm đỉnh gần với src nhất
        int v_min = -1;  // đỉnh cần tìm
        int min_dist = INT_MAX;  // đường đi ngắn từ đỉnh src tới đỉnh đó
        for (int v = 0; v < n; ++v)
            if (!spt[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                v_min = v;
            }
        //  Tối ưu các đỉnh kề của đỉnh vừa tìm được ở trên
        for (int u = 0; u < n; ++u)
            if (!spt[u] && mtx[v_min][u] != 0
                && dist[u] > dist[v_min] + mtx[v_min][u]) {
                dist[u] = dist[v_min] + mtx[v_min][u];
                path[u] = v_min;
            }
        spt[v_min] = true;
    }

    printf("Chi phi ngan nhat tu dinh A den dinh G la: %i\n", dist[n-1]);
    printf("Duong di la: \n");
    int f = n-1;
    while (f != 0) {
        printf("%i ", f);
        f = path[f];
    }
    printf("0\n");
}

int main(int argc, char* argv[]) {
    // Input
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int V, E;
    scanf("%i%i", &V, &E);
    int mtx[N][N];
    for (int i = 0; i < V; ++ i)
        for (int j = 0; j < V; ++j)
            mtx[i][j] = 0;
    for (int e = 0; e < E; ++e) {
        int x, y, z;
        scanf("%i%i%i", &x, &y, &z);
        mtx[x][y] = z;
        mtx[y][x] = z;
    }
    // Solve
    Dijkstra(V, mtx, 0);
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
