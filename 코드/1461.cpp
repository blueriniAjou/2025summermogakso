#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> cont(2, vector<int>());

    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;

        if (input > 0) {
            cont[0].push_back(input);
        }

        else {
            cont[1].push_back(-input);
        }
    }

    int sum = 0;
    int high = 0;

    for (int i = 0; i < 2; ++i) {
        sort(cont[i].begin(), cont[i].end());

        while (cont[i].size()) {
            sum += cont[i][cont[i].size() - 1] << 1;
            high = max(high, cont[i][cont[i].size() - 1]);

            int cnt = M;

            while (cont[i].size() && cnt) {
                cont[i].pop_back();
                --cnt;
            }
        }
    }

    cout << sum - high;
}