#include <iostream>
#include <vector>
using namespace std;

struct Context {
    const vector<char>& chars;
    const vector<int>& charOrder;
    const string& s1;
    const string& s2;
    const string& s3;
};

struct State {
    vector<int>& visited;
    vector<int>& result;
    int& flag;
};

void backtracking(const Context& ctx, State& st) {
    if (st.result.size() == ctx.chars.size()) {
        long long num1 = 0;
        long long num2 = 0;
        long long num3 = 0;

        for (char c : ctx.s1) {
            num1 *= 10;
            num1 += st.result[ctx.charOrder[c - 'A']];
        }

        for (char c : ctx.s2) {
            num2 *= 10;
            num2 += st.result[ctx.charOrder[c - 'A']];
        }

        for (char c : ctx.s3) {
            num3 *= 10;
            num3 += st.result[ctx.charOrder[c - 'A']];
        }

        if (num1 + num2 == num3) {
            st.flag = 1;
        }

        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (st.flag) {
            return;
        }

        if (!st.visited[i]) {
            st.result.push_back(i);
            st.visited[i] = 1;
            backtracking(ctx, st);
            st.result.pop_back();
            st.visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<char> chars;
    vector<int> charOrder(26, -1);
    int cnt = -1;

    for (char c : s1) {
        if (charOrder[c - 'A'] == -1) {
            chars.push_back(c);
            charOrder[c - 'A'] = ++cnt;
        }
    }

    for (char c : s2) {
        if (charOrder[c - 'A'] == -1) {
            chars.push_back(c);
            charOrder[c - 'A'] = ++cnt;
        }
    }

    for (char c : s3) {
        if (charOrder[c - 'A'] == -1) {
            chars.push_back(c);
            charOrder[c - 'A'] = ++cnt;
        }
    }

    if (cnt > 9) {
        cout << "NO";
        return 0;
    }

    vector<int> visited(10, 0);
    vector<int> result;
    result.reserve(chars.size());
    int flag = 0;

    Context ctx{chars, charOrder, s1, s2, s3};
    State st{visited, result, flag};

    backtracking(ctx, st);

    if (flag) {
        cout << "YES";
    }

    else {
        cout << "NO";
    }
}