#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n = 5;

    vector<int> adj[5];

    // Edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    vector<bool> visited(n, false);

    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int nei : adj[node]) {

            if (!visited[nei]) {
                visited[nei] = true;
                q.push(nei);
            }
        }
    }

    return 0;
}
