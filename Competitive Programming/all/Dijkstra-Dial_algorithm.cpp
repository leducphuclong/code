#include<bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define nln '\n'

class  Graph {
    int V;
    list<pair<int, int>> *adj;
 public:
    Graph(int V);
    ~Graph();
    void AddEdGe(int u, int v, int w);
    void ShortestPath(int s, int w);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int>> [V];
}

void Graph::AddEdGe(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::ShortestPath(int src, int w) {
    list<int> bucket[w*V];
    bucket[0].push_back(src);
    vector<pair<int, list<int>::iterator>> dist(V, make_pair(INF, bucket[0].begin()));
    dist[src].first = 0, dist[src].second = bucket[0].begin();
    for (int cost = 0; cost < w*V; ++cost) {
        if (bucket[cost].empty())
            continue;
        while (!bucket[cost].empty()) {
            int u = bucket[cost].front();
            bucket[cost].pop_front();
            for (list<pair<int, int>>::iterator nbh = adj[u].begin(); nbh != adj[u].end(); ++nbh) {
                int v = (*nbh).first;
                int w_v = (*nbh).second;
                if (dist[v].first > dist[u].first+w_v) {
                    if (dist[v].first != INF)
                        bucket[dist[v].first].erase(dist[v].second);
                    bucket[dist[u].first+w_v].push_front(v);
                    dist[v].second = bucket[dist[u].first+w_v].begin();
                    dist[v].first = dist[u].first+w_v;
                }
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d     %d\n", i, dist[i].first);
}

int main() {
    int V = 9;
    Graph G(V);
 
    // makinG above shown Graph
    G.AddEdGe(0, 1, 4);
    G.AddEdGe(0, 7, 8);
    G.AddEdGe(1, 2, 8);
    G.AddEdGe(1, 7, 11);
    G.AddEdGe(2, 3, 7);
    G.AddEdGe(2, 8, 2);
    G.AddEdGe(2, 5, 4);
    G.AddEdGe(3, 4, 9);
    G.AddEdGe(3, 5, 14);
    G.AddEdGe(4, 5, 10);
    G.AddEdGe(5, 6, 2);
    G.AddEdGe(6, 7, 1);
    G.AddEdGe(6, 8, 6);
    G.AddEdGe(7, 8, 7);
 
    // maximum weiGhted edGe - 14
    G.ShortestPath(0, 14);
    cerr << "OK" << nln;
    return 0;
}