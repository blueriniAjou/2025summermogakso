#include <iostream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

void dfs(const vector<vector<int>>& graph, vector<vector<int>>& ancestor, vector<int>& depth, int parent, int u) {
    ancestor[0][u] = parent;
    depth[u] = depth[parent] + 1;

    for (int v : graph[u]) {
        if (parent != v) {
            dfs(graph, ancestor, depth, u, v);
        }
    }
}

void lift(const vector<vector<int>>& ancestor, const int logN, int& v, int d) {
    for (int i = 0; i < logN; ++i) {
        if (d & (1 << i)) {
            v = ancestor[i][v];
        }
    }
}

int lca(const vector<vector<int>>& ancestor, const vector<int>& depth, const int logN, int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    lift(ancestor, logN, v, depth[v] - depth[u]);

    if (u == v) {
        return u;
    }

    for (int i = logN - 1; i > -1; --i) {
        if (ancestor[i][u] != ancestor[i][v]) {
            u = ancestor[i][u];
            v = ancestor[i][v];
        }
    }

    return ancestor[0][u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int N;
    cin >> N;

    int logN = 0;

    while ((1 << logN) <= N) {
        ++logN;
    }

    vector<vector<int>> graph(N + 1, vector<int>());
    vector<vector<int>> ancestor(logN, vector<int>(N + 1, 0));
    vector<int> depth(N + 1, -1);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(graph, ancestor, depth, 0, 1);

    for (int i = 1; i < logN; ++i) {
        for (int j = 1; j < N + 1; ++j) {
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;

        cout << lca(ancestor, depth, logN, u, v) << '\n';
    }
}