#include <iostream>
#include <vector>
#include <algorithm>
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
 
        vector<vector<int>> casino(n, vector<int>(3, 0));
 
        for (int i = 0; i < n; ++i) {
            cin >> casino[i][1] >> casino[i][2] >> casino[i][0];
        }
 
        sort(casino.begin(), casino.end());
 
        for (int i = 0; i < n; ++i) {
            if (casino[i][0] > k && casino[i][1] <= k && k <= casino[i][2]) {
                k = casino[i][0];
            } 
        }
 
        cout << k << '\n';
    }
}