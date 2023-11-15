#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPath(const vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> distance(n, -1); // Initialize distance array with -1 (indicating unvisited)
    vector<int> parent(n, -1); // To keep track of the parent of each vertex
    queue<int> q;

    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end)
            break;

        for (int neighbor : graph[current]) {
            if (distance[neighbor] == -1) {
                q.push(neighbor);
                distance[neighbor] = distance[current] + 1;
                parent[neighbor] = current;
            }
        }
    }

    if (distance[end] == -1) {
        // No path exists from start to end
        return vector<int>();
    }

    // Reconstruct the shortest path
    vector<int> path;
    int current = end;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int numVertices = 7;
    vector<vector<int>> graph(numVertices);

    // Add edges to the graph
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5};
    graph[3] = {1, 6};
    graph[4] = {1, 6};
    graph[5] = {2, 6};
    graph[6] = {3, 4, 5};

    int startVertex = 0;
    int endVertex = 6;

    vector<int> shortest = shortestPath(graph, startVertex, endVertex);

    if (shortest.empty()) {
        cout << "No path exists from vertex " << startVertex << " to " << endVertex << endl;
    } else {
        cout << "Shortest path from vertex " << startVertex << " to " << endVertex << ": ";
        for (int vertex : shortest) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}