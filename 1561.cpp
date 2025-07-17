#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> times(M + 1, 0);

    for (int i = 1; i < M + 1; ++i) {
        cin >> times[i];
    }

    long long low = 0;
    long long high = 6e10;
    long long mid;

    vector<long long> status(M + 1, 0);

    while (low < high) {
        mid = low + (high - low >> 1);

        long long sum = 0;

        for (int i = 1; i < M + 1; ++i) {
            status[i] = mid / times[i] + 1;
            sum += status[i];
        }

        if (sum < N) {
            low = mid + 1;
        }

        else {
            high = mid;
        }
    }

    long long sum = 0;

    for (int i = 1; i < M + 1; ++i) {
        sum += low / times[i] + 1;
    }

    int diff = sum - N;

    for (int i = M; i > 0; --i) {
        if (low % times[i] == 0) {
            if (diff == 0) {
                cout << i;
                break;
            }

            --diff;
        }
    }
}