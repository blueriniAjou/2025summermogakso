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

		vector<int> A(n, 0);
		vector<int> B(n, 0);

		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}

		for (int i = 0; i < n; ++i) {
			cin >> B[i];
		}

		int result = 1;

		for (int i = 0; i < n; ++i) {
			if (A[i] > B[i]) {
				result += A[i] - B[i];
			}
		}

		cout << result << '\n';
	}
}
    