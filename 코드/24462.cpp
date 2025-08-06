#include <iostream>
#include <vector>
using namespace std;

int euclidean(int a, int b) {
    if (a < b) {
        swap(a, b);
    }

    int r = a % b;

    while (r) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<pair<long long, long long>> alarms(N + 1, {0, 0});

    for (int i = 1; i < N + 1; ++i) {
        cin >> alarms[i].first >> alarms[i].second;
    }

    int high = 0;
    pair<int, int> result;

    for (int i = 1; i < N + 1; ++i) {
        for (int j = i + 1; j < N + 1; ++j) {
            int sum = D / alarms[i].second + D / alarms[j].second;

            if (alarms[i].first) {
                sum -= (alarms[i].first - 1) / alarms[i].second;
            }

            if (alarms[j].first) {
                sum -= (alarms[j].first - 1) / alarms[j].second;
            }

            long long gcd = euclidean(alarms[i].second, alarms[j].second);
            long long lcm = alarms[i].second * alarms[j].second / gcd;

            sum -= D / lcm;

            if (max(alarms[i].first, alarms[j].first)) {
                sum += (max(alarms[i].first, alarms[j].first) - 1) / lcm;
            }

            if (!alarms[i].first || !alarms[j].first) {
                ++sum;
            }

            if (high < sum) {
                high = sum;
                result = {i, j};
            }
        }
    }

    cout << result.first << ' ' << result.second << '\n' << high;
}