#include <iostream>
#include <vector>
using namespace std;
 
long long euclidean(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
 
    long long r = a % b;
 
    while (r > 0) {
        a = b;
        b = r;
        r = a % b;
    }
    
    return b;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        long long a, b, k;
        cin >> a >> b >> k;
 
        long long gcd = euclidean(a, b);
 
        if (a / gcd <= k && b / gcd <= k) {
            cout << 1 << '\n';
        }
 
        else {
            cout << 2 << '\n';
        }
    }
}