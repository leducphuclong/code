// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define nln '\n'
#define V 5

// Declare global variables.

int IndexOfMinKey(int key[], bool mstSet[]) {
    int minkey = INT_MAX, min_index = -1;
    for (int i = 0; i < V; ++i)
        if (mstSet[i] == false && key[i] < minkey) {
            minkey = key[i];
            min_index = i;
        }
    return min_index;
}

void primMST(int graph[][V]) {
    int key[V], parent[V];
    bool mstSet[V];
    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
        parent[i] = i;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    for (int count = 1; count <= V-1; ++count) {
        int i = IndexOfMinKey(key, mstSet);
        mstSet[i] = true;
        for (int adj = 0; adj < V; ++adj)
            if (graph[i][adj] && mstSet[adj] == false &&
                graph[i][adj] < key[adj]) {
                key[adj] = graph[i][adj];
                parent[adj] = i;
            }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%i - %i : %i\n", parent[i], i, graph[i][parent[i]]);
}

int main(int argc, char* argv[]) {
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}
