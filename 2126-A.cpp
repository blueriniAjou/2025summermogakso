#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int x;
        cin >> x;
 
        int low = 10;
 
        while (x > 0) {
            low = min(low, x % 10);
            x /= 10;
        }
 
        cout << low << '\n';
    }
}