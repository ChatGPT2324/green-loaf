#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> color;
int n;

bool isSafe(int node, vector<vector<int>> &graph, vector<int> &color, int col) {
    for(auto neighbor : graph[node]) {
        if(color[neighbor] == col) {
            return false;
        }
    }
    return true;
}

bool colorGraph(int node, vector<vector<int>> &graph, int N, int m, vector<int> &color) {

    if(node == N) return true;

    for(int i = 1; i <= m; i++) {

        if(isSafe(node, graph, color, i)) {

            color[node] = i;

            if(colorGraph(node + 1, graph, N, m, color)) {
                return true;
            }

            color[node] = 0;
        }
    }

    return false;
}

bool checkGraph(vector<vector<int>> &graph, int m) {
    return colorGraph(0, graph, n, m, color);
}

int main() {

    n = 4;
    int m = 3;

    graph.resize(n);
    color.assign(n, 0);

    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);

    graph[2].push_back(0);

    graph[3].push_back(1);

    cout << (checkGraph(graph, m) ? "Possible" : "Not Possible");

    return 0;
}