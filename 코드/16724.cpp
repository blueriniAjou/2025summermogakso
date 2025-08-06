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

    vector<vector<vector<pair<int, int>>>> graph(N, vector<vector<pair<int, int>>>(M, vector<pair<int, int>>()));

    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;

        for (int j = 0; j < M; ++j) {
            if (input[j] == 'L') {
                graph[i][j].push_back({i, j - 1});
                graph[i][j - 1].push_back({i, j});
            }

            if (input[j] == 'R') {
                graph[i][j].push_back({i, j + 1});
                graph[i][j + 1].push_back({i, j});
            }

            if (input[j] == 'U') {
                graph[i][j].push_back({i - 1, j});
                graph[i - 1][j].push_back({i, j});
            }

            if (input[j] == 'D') {
                graph[i][j].push_back({i + 1, j});
                graph[i + 1][j].push_back({i, j});
            }
        }
    }

    vector<vector<int>> visited(N, vector<int>(M, 0));
    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j]) {
                ++cnt;
                list<pair<int, int>> bfsQueue{{i, j}};
                visited[i][j] = 1;

                while (bfsQueue.size()) {
                    auto [ui, uj] = bfsQueue.front();
                    bfsQueue.pop_front();
                    
                    for (auto [vi, vj] : graph[ui][uj]) {
                        if (!visited[vi][vj]) {
                            bfsQueue.push_back({vi, vj});
                            visited[vi][vj] = 1;
                        }
                    }
                }
            }
        }
    }

    cout << cnt;
}