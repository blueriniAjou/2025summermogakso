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
 
        vector<int> towers(n, 0);
 
        for (int i = 0; i < n; ++i) {
            cin >> towers[i];
        }
 
        int currTower = towers[k - 1];
        int currWater = 1;
        sort(towers.begin(), towers.end());
 
        int flag = 1;
 
        for (int i = 0; i < n; ++i) {
            if (currTower >= towers[i]) {
                continue;
            }
 
            currWater += towers[i] - currTower - 1;
 
            if (currTower < currWater) {
                flag = 0;
                break;
            }
 
            currTower = towers[i];
            ++currWater;
        }
 
        if (flag) {
            cout << "YES\n";
        }
 
        else {
            cout << "NO\n";
        }
    }
}