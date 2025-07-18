#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> result;
    result.reserve(n);
    
    for (int i = 1; i < m + 1; ++i) {
        if (i == k || i <= (i ^ k)) {
            result.push_back(i);
        }

        if (result.size() == n) {
            break;
        }
    }

    if (result.size() < n) {
        cout << -1;
        return 0;
    }

    for (int i : result) {
        cout << i << ' ';
    }
}