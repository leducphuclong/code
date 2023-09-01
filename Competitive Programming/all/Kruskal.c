// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define nln '\n'

const int N = 15e3;

// Declare global variables.
int Edge[1000][3];
int Parent[1000];
int V, E;

void getdata() {
    scanf("%i%i", &V, &E);
    int t = E;
    for (int i = 0; i < E; ++i) {
        scanf("%i%i%i", &Edge[i][0], &Edge[i][1], &Edge[i][2]);
    }
}

void swap(int a[], int b[]) {
    for (int i = 0; i < 3; ++i) {
        int t = a[i];
        a[i] = b[i];
        b[i] = t;
    }
}

void sort() {
    for (int i = 0; i < E-1; ++i)
        for (int j = i+1; j < E; ++j)
            if (Edge[i][2] > Edge[j][2]) {
                swap(Edge[i], Edge[j]);
            }
}

void build_sets() {
    for (int i = 0; i < V; ++i)
        Parent[i] = i;
}

int find(int i) {
    if (Parent[i] == i)
        return i;
    return Parent[i];
}

void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv)
        return;
    Parent[pu] = pv;
}

void kruskals_mst() {
    printf("Following are the edges in the constructed MST\n");
    int ans = 0, cnt = 1;
    for (int e = 0; e < E; ++e) {
        int u = Edge[e][0];
        int v = Edge[e][1];
        int c = Edge[e][2];
        if (find(u) != find(v)) {
            unite(u, v);
            ans += c;
            ++cnt;
            printf("%i -- %i == %i\n", u, v, c);
            if (cnt == V)
                break;
        }
    }
    printf("Minimum Cost Spanning Tree: %i\n", ans);
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    getdata();
    sort();
    build_sets();
    kruskals_mst();
    return 0;
}
