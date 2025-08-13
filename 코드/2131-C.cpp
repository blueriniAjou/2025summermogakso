#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		map<int, int> cntS;
		map<int, int> cntT;

		for (int i = 0; i < n << 1; ++i) {
			int input;
			cin >> input;

			int value;

			if (input % k > k >> 1) {
				value = k - (input % k);
			}

			else {
				value = input % k;
			}

			if (i < n) {
				++cntS[value];
			}

			else {
				++cntT[value];
			}
		}

		int flag = 1;

		for (const auto& [value, cnt] : cntS) {
			if (cnt != cntT[value]) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			cout << "YES\n";
		}

		else {
			cout << "NO\n";
		}
	}
}
    