#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        string input;
        cin >> input;
 
        sort(input.begin(), input.end(), [](const char& a, const char& b) {
            return a > b;
        });
 
        cout << input << '\n';
    }
}