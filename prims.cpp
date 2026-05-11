#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void prims(int start, vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();

    vector<int> visited(n, 0);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    pq.push({0, start});

    int mstWeight = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = 1;
        mstWeight += weight;

        for (auto it : graph[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    cout << "Total MST Weight = " << mstWeight << endl;
}

int main() {
    int n = 5;

    vector<vector<pair<int, int>>> graph(n);

    // Undirected graph
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});

    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    prims(0, graph);

    return 0;
}