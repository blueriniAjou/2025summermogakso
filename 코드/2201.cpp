#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    vector<long long> dp{1, 1, 1};

    for (int i = 3; i < 87; ++i) {
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }

    long long K;
    cin >> K;

    int flag = 1;
    string result = "1";
    int digit = -1;

    while (true) {
        long long prefixSum = 0;
        int i = 0;

        for (; ; ++i) {
            prefixSum += dp[i];

            if (K < prefixSum) {
                break;
            }
        }

        if (flag) {
            flag  = 0;
        }

        else {
            for (int j = 0; j < digit - i - 1; ++j) {
                result += '0';
            }

            if (i > 0) {
                result += '1';
            }
        }

        digit = i;

        if (digit < 2) {
            break;
        }

        prefixSum -= dp[i];
        K -= prefixSum;
    }

    cout << result;
}