#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

int check(int N, int L, const vector<int>& v) {
    int prev = v[0];
    int cnt = 0;
    int flag = 1;

    for (int i = 0; i < N; ++i) {
        if (abs(prev - v[i]) > 1) {
            return 0;
        }

        if (prev == v[i]) {
            ++cnt;
        }

        else {
            if (!flag) {
                return 0;
            }

            if (prev < v[i]) {
                if (cnt < L) {
                    return 0;
                }
            }

            if (prev > v[i]) {
                flag = 0;
            }

            cnt = 1;
        }

        if (!flag && cnt == L) {
            flag = 1;
            cnt = 0;
        }

        prev = v[i];
    }

    return flag;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, L;
    cin >> N >> L;

    vector<vector<int>> space(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> space[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < N; ++i) {
        result += check(N, L, space[i]);
    }

    for (int i = 0; i < N; ++i) {
        vector<int> temp(N, 0);

        for (int j = 0; j < N; ++j) {
            temp[j] = space[j][i];
        }

        result += check(N, L, temp);
    }

    cout << result;
}