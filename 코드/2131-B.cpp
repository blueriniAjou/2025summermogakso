#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				if (i == n - 1) {
					cout << 2 << ' ';
				}

				else {
					cout << 3 << ' ';
				}
			}

			else {
				cout << -1 << ' ';
			}
		}

		cout << '\n';
	}
}
    