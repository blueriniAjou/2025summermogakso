#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void backtracking(const vector<int>& num, vector<int>& visited, deque<int>& result, int& high, int curr) {
    if (curr == num.size()) {
        deque<int> check = result;
        int cnt = 0;

        for (int i = 0; i < num.size(); ++i) {
            int sum = 0;

            for (int j = 0; j < num.size(); ++j) {
                sum += check[j];

                if (sum == 50) {
                    ++cnt;
                    break;
                }
            }

            check.push_back(check.front());
            check.pop_front();
        }

        high = max(high, cnt / 2);
    }

    for (int i = 0; i < num.size(); ++i) {
        if (!visited[i]) {
            result.push_back(num[i]);
            visited[i] = 1;
            backtracking(num, visited, result, high, curr + 1);
            result.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> num(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }

    int high = 0;
    vector<int> visited(N, 0);
    deque<int> result;

    backtracking(num, visited, result, high, 0);
    cout << high;
}