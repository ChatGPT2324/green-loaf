#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[5];
vector<bool> visited(5, false);

void dfs(int node) {

    visited[node] = true;

    cout << node << " ";

    for (int nei : adj[node]) {

        if (!visited[nei]) {
            dfs(nei);
        }
    }
}

int main() {

    // Edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    dfs(0);

    return 0;
}
