#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> man(n + 1, 0);
    vector<int> woman(m + 1, 0);

    for (int i = 1; i < n + 1; ++i) {
        cin >> man[i];
    }

    for (int i = 1; i < m + 1; ++i) {
        cin >> woman[i];
    }

    if (n > m) {
        swap(n, m);
        swap(man, woman);
    }

    sort(man.begin(), man.end());
    sort(woman.begin(), woman.end());

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (i > j) {
                continue;
            }

            else if (i < j) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(man[i] - woman[j]));
            }

            else {
                dp[i][j] = dp[i - 1][j - 1] + abs(man[i] - woman[j]);
            }
        }
    }

    cout << dp[n][m];
}