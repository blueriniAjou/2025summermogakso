#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> sub(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> sub[i];
	}

	int l = 0;
	int r = 0;
	int cnt = sub[0] & 1;
	int high = !(sub[0] & 1);

	while (l < N - 1) {
		int move;

		if (r == N - 1) {
			move = 1;
		}

		else if (l == r) {
			move = 0;
		}

		else if (cnt > K) {
			move = 1;
		}

		else {
			move = 0;
		}

		if (move) {
			if (sub[l] & 1) {
				--cnt;
			}

			++l;
		}

		else {
			++r;

			if (sub[r] & 1) {
				++cnt;
			}
		}

		if (cnt <= K) {
			high = max(high, r - l + 1 - cnt);
		}
	}

	cout << high;
}