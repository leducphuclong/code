// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <limits.h>

#define nln '\n'
#define N 100

// Declare global variables.

int main(int argc, char* argv[]) {
    // Input
    int mtx[N][N], n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++j)
            scanf("%i", &mtx[i][j]);
    // Floyd Warshall's Algorithm
    for (int itm = 0; itm < n; ++itm)
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                if (mtx[u][v] && mtx[u][itm] && mtx[itm][v] && mtx[u][v] > mtx[u][itm] + mtx[itm][v])
                    mtx[u][v] = mtx[u][itm] + mtx[itm][v];
    // Output the result
    for (int v = 0; v < n; ++v)
        printf("Duong di ngan nhat tu dinh 0 den dinh %i: %i\n", v, mtx[0][v]);
    return 0;
}
