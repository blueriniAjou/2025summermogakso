#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V + 1, vector<pair<int, int>>());

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> visited(V + 1, 0);
    visited[1] = 1;
    int sum = 0;
    
    for (const auto& [v, w] : graph[1]) {
        if (!visited[v]) {
            pq.push({w, v});
        }
    }

    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = 1;
        sum += w;

        for (const auto& [v, w] : graph[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << sum;
}