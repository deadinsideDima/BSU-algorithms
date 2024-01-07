#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, const vector<vector<int>>& adjMatrix, vector<bool>& visited, vector<pair<int, int>>& edges) {
    visited[u] = true;

    for (int v = 0; v < adjMatrix.size(); ++v) {
        if (adjMatrix[u][v] == 1 && !visited[v]) {
            edges.emplace_back(u + 1, v + 1);
            dfs(v, adjMatrix, visited, edges);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> adjMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
        }
    }
    vector<bool> visited(n, false);
    vector<pair<int, int>> edges;
    dfs(0, adjMatrix, visited, edges);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << edges.size() << endl;
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }
    return 0;
}
