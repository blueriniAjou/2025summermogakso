#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		int value = 0;

		for (int i = sqrt(N); i > 0; --i) {
			if (((N / i) & 1) == (i & 1)) {
				if (N % i == 0) {
					value = i;
					break;
				}
			}
		}

		if (value) {
			int l = N / value;
			int r = N / value;

			if (!(N & 1)) {
				--l;
				++r;
			}

			l -= value - 1 >> 1 << 1;
			r += value - 1 >> 1 << 1;
			
			cout << (l >> 1) << ' ' << (r + 1 >> 1) << '\n'; 
		}

		else {
			cout << "IMPOSSIBLE\n";
		}
	}
}