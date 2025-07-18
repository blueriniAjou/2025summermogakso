#include <iostream>
#include <vector>
#include <list>
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

    list<int> sortQueue;

    for (int i = 1; i < N + 1; ++i) {
        if (inDegree[i] == 0) {
            sortQueue.push_back(i);
        }
    }

    vector<int> result;
    result.reserve(N);

    while (sortQueue.size()) {
        int u = sortQueue.front();
        result.push_back(u);
        sortQueue.pop_front();

        for (int v : graph[u]) {
            if (--inDegree[v] == 0) {
                sortQueue.push_back(v);
            }
        }
    }

    for (int i : result) {
        cout << i << ' ';
    }
}