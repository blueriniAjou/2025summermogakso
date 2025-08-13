#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	while (true) {
		int m;
		cin >> m;

		if (!m) {
			break;
		}

		string S;
		cin.ignore();
		getline(cin, S);

		vector<int> ascii(128, 0);

		int l = 0;
		int r = 0;
		int cnt = 1;
		int high = 1;
		++ascii[S[0]];

		while (l < S.size() - 1) {
			int move;

			if (r == S.size() - 1) {
				move = 1;
			}

			else if (l == r) {
				move = 0;
			}

			else if (cnt > m) {
				move = 1;
			}

			else {
				move = 0;
			}

			if (move) {
				if (!--ascii[S[l]]) {
					--cnt;
				}

				++l;
			}

			else {
				++r;

				if (!ascii[S[r]]++) {
					++cnt;
				}
			}

			if (cnt <= m) {
				high = max(high, r - l + 1);
			}
		}

		cout << high << '\n';
	}
}