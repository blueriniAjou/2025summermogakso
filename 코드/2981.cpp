#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int euclidean(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    
    if (!b) {
        return a;
    }

    int r = a % b;

    while (r) {
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

    int N;
    cin >> N;
    
    int standard;
    cin >> standard;
    
    int gcd = 0;

    for (int i = 0; i < N - 1; ++i) {
        int input;
        cin >> input;

        gcd = euclidean(gcd, abs(input - standard));
    }

    vector<int> result;

    for (int i = 1; i <= sqrt(gcd); ++i) {
        if (gcd % i == 0) {
            if (i) {
                result.push_back(i);
            }

            if (i != gcd / i) {
                result.push_back(gcd / i);
            }
        }
    }

    sort(result.begin(), result.end());

    for (int i : result) {
        if (i > 1) {
            cout << i << ' ';
        }
    }
}