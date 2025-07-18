#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void topologicalSort(int N, int W, const vector<int>& time, const vector<vector<int>>& graph, vector<int>& inDegree) {
    list<pair<int, long long>> sortQueue;
    vector<long long> prevTime(N + 1, 0);

    for (int i = 1; i < N + 1; ++i) {
        if (inDegree[i] == 0) {
            sortQueue.push_back({i, time[i]});
        }
    }

    while (sortQueue.size()) {
        auto [u, t] = sortQueue.front();
        sortQueue.pop_front();

        for (int v : graph[u]) {
            prevTime[v] = max(prevTime[v], t + time[v]);

            if (--inDegree[v] == 0) {
                if (v == W) {
                    cout << prevTime[W] << '\n';
                    return;
                }

                sortQueue.push_back({v, prevTime[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> time(N + 1, 0);
        vector<vector<int>> graph(N + 1, vector<int>());
        vector<int> inDegree(N + 1, 0);

        for (int i = 1; i < N + 1; ++i) {
            cin >> time[i];
        }

        for (int i = 0; i < K; ++i) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            ++inDegree[v];
        }

        int W;
        cin >> W;

        if (inDegree[W] == 0) {
            cout << time[W] << '\n';
            continue;
        }

        topologicalSort(N, W, time, graph, inDegree);
    }
}