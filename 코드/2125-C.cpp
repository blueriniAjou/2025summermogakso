#include <iostream>
#include <vector>
using namespace std;
 
void recursion(const vector<int>& prime, vector<int>& visited, long long& result, long long l, long long r, long long& cnt, int depth, int curr, int sign) {
    if (depth == 0) {
        if (l % result) {
            l += result - (l % result);
        }
 
        if (r % result) {
            r -= r % result;
        }
 
        cnt += sign * max(0LL, (r - l) / result + 1);
        return;
    }
    
    for (int i = curr; i < 4; ++i) {
        if (visited[i]) {
            continue;
        }
 
        result *= prime[i];
        visited[i] = 1;
        recursion(prime, visited, result, l, r, cnt, depth - 1, i + 1, sign);
        result /= prime[i];
        visited[i] = 0;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        long long l, r;
        cin >> l >> r;
 
        long long cnt = r - l + 1;
 
        vector<int> prime{2, 3, 5, 7};
 
        int sign = -1;
 
        for (int i = 1; i < 5; ++i) {
            long long result = 1;
            vector<int> visited(4, 0);
 
            recursion(prime, visited, result, l, r, cnt, i, 0, sign);
            sign *= -1;
        }
 
        cout << cnt << '\n';
    }
}