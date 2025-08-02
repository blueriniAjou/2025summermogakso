#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, B, W;
    cin >> N >> B >> W;

    string stones;
    cin >> stones;

    int l = 0;
    int r = 0;
    int bCnt = stones[0] == 'B';
    int wCnt = stones[0] == 'W';
    int result = 0;

    while (r < N - 1) {
        if (W <= wCnt && B >= bCnt) {
            result = max(result, r - l + 1);
        }

        if (l == r) {
            ++r;
            bCnt += stones[r] == 'B';
            wCnt += stones[r] == 'W';
            continue;
        }

        if (B >= bCnt) {
            ++r;
            bCnt += stones[r] == 'B';
            wCnt += stones[r] == 'W';
        }
        
        else {
            bCnt -= stones[l] == 'B';
            wCnt -= stones[l] == 'W';
            ++l;
        }
    }

    while (l < N) {
        if (W <= wCnt && B >= bCnt) {
            result = max(result, r - l + 1);
        }
        
        bCnt -= stones[l] == 'B';
        wCnt -= stones[l] == 'W';
        ++l;
    }

    cout << result;
}