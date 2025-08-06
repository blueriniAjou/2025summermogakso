#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>>& graph, vector<int>& dp, int curr) {
    for (int child : graph[curr]) {
        dp[child] += dp[curr];
        dfs(graph, dp, child);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> dp(n + 1, 0);

    for (int i = 1; i < n + 1; ++i) {
        int parent;
        cin >> parent;

        if (parent != -1) {
            graph[parent].push_back(i);
        }
    }

    for (int i = 0; i < m; ++i) {
        int idx, w;
        cin >> idx >> w;

        dp[idx] += w;
    }

    dfs(graph, dp, 1);

    for (int i = 1; i < n + 1; ++i) {
        cout << dp[i] << ' ';
    }
}
