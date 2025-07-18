#include <iostream>
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
 
        int cnt = 0;
        int combo = 0;
        int skip = 0;
 
        for (int i = 0; i < n; ++i) {
            int input;
            cin >> input;
 
            if (skip) {
                skip = 0;
                continue;
            }
 
            if (input) {
                combo = 0;
            }
 
            else {
                ++combo;
 
                if (combo == k) {
                    ++cnt;
                    combo = 0;
                    skip = 1;
                }
            }
        }
 
        cout << cnt << '\n';
    }
}