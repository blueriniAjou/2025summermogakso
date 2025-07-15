#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<string> result{"*"};

    for (int i = 2; i < N + 1; ++i) {
        int width = (1 << i + 1) - 3;
        int height = (1 << i) - 1;
        int l;
        int r;
        int addL;
        int addR;
        int prevPointer = 0;

        vector<string> cont;
        cont.reserve(height);

        if (i & 1) {
            l = width >> 1;
            r = width >> 1;
            addL = -1;
            addR = 1;
        }

        else {
            l = 1;
            r = width - 2;
            addL = 1;
            addR = -1;

            string curr = "";

            for (int j = 0; j < width; ++j) {
                curr += '*';
            }

            cont.push_back(curr);
        }

        for (int j = 0; j < height - 1; ++j) {
            string curr = "";
            int pointer = 0;

            while (l > pointer) {
                curr += ' ';
                ++pointer;
            }

            curr += '*';
            ++pointer;

            if (l == r) {
                cont.push_back(curr);

                l += addL;
                r += addR;

                continue;
            }

            int flag;
            int blank;

            if ((i & 1) && (j >= height - 1 - result.size())) {
                flag = 1;
                blank = prevPointer;
            }

            else if (!(i & 1) && (j < result.size())) {
                flag = 1;
                blank = result.size() - 1 - prevPointer;
            }

            else {
                flag = 0;
                blank = 0;
            }

            if (flag) {
                while (l + blank >= pointer) {
                    curr += ' ';
                    ++pointer;
                }

                for (char c : result[prevPointer]) {
                    curr += c;
                    ++pointer;
                }

                ++prevPointer;
            }

            while (r > pointer) {
                curr += ' ';
                ++pointer;
            }

            curr += '*';
            cont.push_back(curr);

            l += addL;
            r += addR;
        }

        if (i & 1) {
            string curr = "";

            for (int j = 0; j < width; ++j) {
                curr += '*';
            }

            cont.push_back(curr);
        }

        result = move(cont);
    }

    for (string s : result) {
        cout << s << '\n';
    }
}