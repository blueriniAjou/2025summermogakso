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
		int n;
		cin >> n;

		vector<int> A(n + 1, 0);
		vector<int> B(n + 1, 0);

		for (int i = 1; i < n + 1; ++i) {
			cin >> A[i];
		}

		for (int i = 1; i < n + 1; ++i) {
			cin >> B[i];
		}

		int flag = 1;

		if (A[n] != B[n]) {
			flag = 0;
		}

		for (int i = 1; i < n; ++i) {
			if (A[i] == B[i] || (A[i] ^ A[i + 1]) == B[i] || (A[i] ^ B[i + 1]) == B[i]) {
				continue;
			}

			flag = 0;
			break;
		}

		if (flag) {
			cout << "YES\n";
		}

		else {
			cout << "NO\n";
		}
	}
}
    