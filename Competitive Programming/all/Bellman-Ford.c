// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <limits.h>

#define nln '\n'
#define N 100

// Declare global variables.

struct Edge {
    int src, dest, weight;
};

int V, E;
struct Edge Edges[N];

void printArr(int dist[], int n, int src) {
    printf("\n");
    for (int i = 0; i < n; ++i)
        printf("Khoang cach tu dinh %d den nguon %d la %d\n", i, src, dist[i]);
}

void BellmanFord(int src) {
    int dist[V];
    // Khoảng cách từ đỉnh gốc để mọi đỉnh ban đầu bằng vô cùng
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = Edges[j].src;
            int v = Edges[j].dest;
            int weight = Edges[j].weight;
            if (dist[u] != INT_MAX
                && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    // Sau khi đã tối ưu mảng dist là đường ngắn nhất đến tất cả đỉnh,
    // nếu vẫn còn đường đi ngắn hơn từ đỉnh gốc đến một
    // đỉnh nào đó bất kì, thì chứng tỏ đồ thị chưa chu trình âm
    for (int i = 0; i < E; i++) {
        int u = Edges[i].src;
        int v = Edges[i].dest;
        int weight = Edges[i].weight;
        if (dist[u] != INT_MAX
            && dist[u] + weight < dist[v]) {
            printf("Do thi co chu trinh am");
            return;
        }
    }
    printArr(dist, V, src);
    return;
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

    BellmanFord(0);

    return 0;
}
