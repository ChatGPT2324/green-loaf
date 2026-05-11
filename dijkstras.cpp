#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, 1e9);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : graph[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if (d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int n = 5;

    vector<vector<pair<int, int>>> graph(n);

    // {neighbor, weight}
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});

    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});

    graph[2].push_back({4, 3});

    graph[3].push_back({4, 1});

    dijkstra(0, graph);

    return 0;
}