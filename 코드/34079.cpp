#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>());

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    list<pair<int, int>> bfsQueue{{N, 1}};
    vector<int> bfsVisited(N + 1, 0);
    vector<vector<int>> prev(N + 1, vector<int>());
    bfsVisited[N] = 1;

    while (bfsQueue.size()) {
        auto [u, t] = bfsQueue.front();
        bfsQueue.pop_front();

        for (int v : graph[u]) {
            if (!bfsVisited[v]) {
                bfsQueue.push_back({v, t + 1});
                bfsVisited[v] = t + 1;
            }

            if (bfsVisited[v] == t + 1) {
                prev[v].push_back(u);
            }
        }
    }

    vector<int> poss;
    list<int> tracebackQueue = {1};
    vector<int> tracebackVisited(N + 1, 0);
    vector<vector<int>> topology(N + 1, vector<int>());

    while (tracebackQueue.size()) {
        int u = tracebackQueue.front();
        tracebackQueue.pop_front();
        poss.push_back(u);
        topology[bfsVisited[u]].push_back(u);

        for (int v : prev[u]) {
            if (!tracebackVisited[v]) {
                tracebackQueue.push_back(v);
                tracebackVisited[v] = 1;
            }
            
        }
    }

    for (const vector<int>& v : topology) {
        if (v.size() == 1 && v[0] != 1 && v[0] != N) {
            cout << v[0];
            return 0;
        }
    }
    cout << 1;
}