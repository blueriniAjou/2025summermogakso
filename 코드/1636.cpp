#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> input(N, {0, 0});

    for (int i = 0; i < N; ++i) {
        cin >> input[i].first >> input[i].second;
    }

    int init = 0;
    int low = numeric_limits<int>::max();

    for (int i = 1; i < 201; ++i) {
        int curr = i;
        int sum = 0;

        for (int j = 0; j < N; ++j) {
            const auto& [s, e] = input[j];

            if (s <= curr && curr <= e) {
                ;
            }

            else if (s > curr) {
                sum += s - curr;
                curr = s;
            }

            else if (curr > e) {
                sum += curr - e;
                curr = e;
            }
        }

        if (low > sum) {
            init = i;
            low = sum;
        }
    }

    cout << low << '\n';

    int curr = init;

    for (int j = 0; j < N; ++j) {
        const auto& [s, e] = input[j];

        if (s <= curr && curr <= e) {
            ;
        }

        else if (s > curr) {
            curr = s;
        }

        else if (curr > e) {
            curr = e;
        }

        cout << curr << '\n';
    }
}