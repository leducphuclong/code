// Copyright 2023 (c, Le Duc Phuc Long
#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef int lo;

int N = 100;

// Global Variables
lo G[100][100], V, E, S, F;

void input() {
    freopen("in", "r", stdin);
    scanf("%i%i%i%i", &V, &E, &S, &F);
    while (E--) {
        lo x, y, z;
        scanf("%i%i%i", &x, &y, &z);
        G[x][y] = z;
        G[y][x] = z;
    }
}

void show(lo n, lo a[]) {
    for (lo i = 1; i <= n; ++i)
        if (a[i] != INT_MAX)
            printf("%i ", a[i]);
        else
            printf("MAX ");
    printf("\n");
}

void Dijkstra() {
    lo L[V+1], P[V+1], B[V+1];
    memset(B, 0, V*sizeof(B[0]));
    for (lo i = 0; i <= V; ++i)
        L[i] = INT_MAX;
    L[S] = 0;
    lo C = V+1;
    while (C--) {
        show(V, L);
        lo miv = INT_MAX, loc = -1;
        for (lo i = 1; i <= V; ++i) {
            if (!B[i] && L[i] < miv) {
                miv = L[i];
                loc = i;
            }
        }
        printf("L loc: %i\n", L[loc]);
        for (lo i = 1; i <= V; ++i)
            if (!B[i] && G[loc][i] != 0 && L[i] > L[loc] + G[loc][i]) {
                L[i] = L[loc]+G[loc][i];
                P[i] = loc;
            }
        B[loc] = 1;
        L[loc] = INT_MAX;
    }
    printf("kq: %i\n", P[F]);
}

int main() {
    input();
    Dijkstra();
    return 0;
}
