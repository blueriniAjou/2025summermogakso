#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> inDegree(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        ++inDegree[v];
    }

    priority_queue<int, vector<int>, greater<>> sortQueue;

    for (int i = 1; i < N + 1; ++i) {
        if (inDegree[i] == 0) {
            sortQueue.push(i);
        }
    }

    while (sortQueue.size()) {
        int u = sortQueue.top();
        cout << u << ' ';
        sortQueue.pop();

        for (int v : graph[u]) {
            if (--inDegree[v] == 0) {
                sortQueue.push(v);
            }
        }
    }
}