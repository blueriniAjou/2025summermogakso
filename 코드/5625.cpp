#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> xSum (1000002, 0);
    vector<int> ySum (1000002, 0);

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        ++xSum[min({x1, x2, x3}) + 1];
        --xSum[max({x1, x2, x3})];
        ++ySum[min({y1, y2, y3}) + 1];
        --ySum[max({y1, y2, y3})];
    }

    for (int i = 1; i < 1000002; ++i) {
        xSum[i] += xSum[i - 1];
        ySum[i] += ySum[i - 1];
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        char query, dummy;
        int value;
        cin >> query >> dummy >> value;

        if (query == 'x') {
            cout << xSum[value] << '\n';
        }

        if (query == 'y') {
            cout << ySum[value] << '\n';
        }
    }
}