#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> graph(n + 1, vector<int>());

		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		int high = 0;
		int cntEnd = 0;

		for (int i = 1; i < n + 1; ++i) {
			if (graph[i].size() == 1) {
				++cntEnd;
			}
		}

		for (int i = 1; i < n + 1; ++i) {
			int cnt = 0;
			
			if (graph[i].size() == 1) {
				++cnt;
			}

			for (int v : graph[i]) {
				if (graph[v].size() == 1) {
					++cnt;
				}
			}

			high = max(high, cnt);
		}

		cout << cntEnd - high << '\n';
	}
}
    