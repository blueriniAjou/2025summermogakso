#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>>& graph, vector<pair<int, int>>& dp, int parent, int u) {
    for (int v : graph[u]) {
        if (v != parent) {
            dfs(graph, dp, u, v);

            dp[u].first += dp[v].second;
            dp[u].second += max(dp[v].first, dp[v].second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1, vector<int>());
    vector<pair<int, int>> dp(N + 1, {0, 0});

    for (int i = 1; i < N + 1; ++i) {
        cin >> dp[i].first;
    }

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(graph, dp, 0, 1);

    cout << max(dp[1].first, dp[1].second);
}