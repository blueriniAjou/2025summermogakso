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
    vector<int> inDegree(N + 1, 0);
    
    for (int i = 0; i < M; ++i) {
        int singerCnt;
        cin >> singerCnt;

        int prev = -1;

        for (int j = 0; j < singerCnt; ++j) {
            int input;
            cin >> input;

            if (j) {
                graph[prev].push_back(input);
                ++inDegree[input];
            }

            prev = input;
        }
    }

    list<int> sortQueue;
    vector<int> result;
    result.reserve(N);

    for (int i = 1; i < N + 1; ++i) {
        if (inDegree[i] == 0) {
            sortQueue.push_back(i);
        }
    }

    while (sortQueue.size()) {
        int u = sortQueue.front();
        sortQueue.pop_front();
        result.push_back(u);

        for (int v : graph[u]) {
            if (--inDegree[v] == 0) {
                sortQueue.push_back(v);
            }
        }
    }

    if (result.size() == N) {
        for (int i : result) {
            cout << i << '\n';
        }
    }

    else {
        cout << 0;
    }
}