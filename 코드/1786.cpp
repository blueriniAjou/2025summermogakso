#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string T;
    getline(cin, T);

    string P;
    getline(cin, P);

    int N = T.size();
    int M = P.size();

    vector<int> pi(M, 0);

    for (int i = 1, j = 0; i < M;) {
        if (P[i] == P[j]) {
            pi[i++] = ++j;
        }

        else if (j) {
            j = pi[j - 1];
        }

        else {
            pi[i++] = 0;
        }
    }

    vector<int> result;

    for (int i = 0, j = 0; i < N;) {
        if (T[i] == P[j]) {
            ++i;
            ++j;

            if (j == M) {
                result.push_back(i - M);
                j = pi[j - 1];
            }
        }

        else if (j) {
            j = pi[j - 1];
        }

        else {
            ++i;
        }
    }

    cout << result.size() << '\n';

    for (int i : result) {
        cout << i + 1 << ' ';
    }
}