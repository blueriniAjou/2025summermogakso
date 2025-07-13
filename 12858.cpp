#include <iostream>
#include <vector>
using namespace std;

long long euclidean(long long a, long long b) {
    a = abs(a);
    b = abs(b);

    if (a < b) {
        swap(a, b);
    }

    if (b == 0) {
        return a;
    }

    long long r = a % b;

    while (r > 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

struct SegmentTree {
    vector<long long> treeValue;
    vector<long long> treeGCD;

    SegmentTree(const vector<int>& v) {
        int size = 1;

        while (size < v.size()) {
            size <<= 1;
        }
        
        treeValue.assign(size << 1, 0);
        treeGCD.assign(size << 1, 0);
        build(v, 1, 0, v.size() - 1);
    }

    void build(const vector<int>& v, int node, int l, int r) {
        if (l == r) {
            treeValue[node] = v[l];
            treeGCD[node] = v[l];
            return;
        }

        int m = l + (r - l >> 1);

        build(v, node << 1, l, m);
        build(v, node << 1 | 1, m + 1, r);

        treeValue[node] = treeValue[node << 1] + treeValue[node << 1 | 1];
        treeGCD[node] = euclidean(treeGCD[node << 1], treeGCD[node << 1 | 1]);
    }

    long long valueQuery(int node, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) {
            return 0;
        }

        if (ql <= l && r <= qr) {
            return treeValue[node];
        }

        int m = l + (r - l >> 1);

        return valueQuery(node << 1, l, m, ql, qr) + valueQuery(node << 1 | 1, m + 1, r, ql, qr);
    }

    long long GCDQuery(int node, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) {
            return 0;
        }

        if (ql <= l && r <= qr) {
            return treeGCD[node];
        }

        int m = l + (r - l >> 1);

        return euclidean(GCDQuery(node << 1, l, m, ql, qr), GCDQuery(node << 1 | 1, m + 1, r, ql, qr));
    }

    void update(int node, int l, int r, int index, int value) {
        if (index < l || r < index) {
            return;
        }

        if (l == r) {
            treeValue[node] += value;
            treeGCD[node] += value;
            return;
        }

        int m = l + (r - l >> 1);

        update(node << 1, l, m, index, value);
        update(node << 1 | 1, m + 1, r, index, value);

        treeValue[node] = treeValue[node << 1] + treeValue[node << 1 | 1];
        treeGCD[node] = euclidean(treeGCD[node << 1], treeGCD[node << 1 | 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> sub(N + 1, 0);
    vector<int> diff(N + 2, 0);

    for (int i = 1; i < N + 1; ++i) {
        cin >> sub[i];
        diff[i] = sub[i] - sub[i - 1];
    }

    SegmentTree st(diff);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int T, A, B;
        cin >> T >> A >> B;

        if (T) {
            st.update(1, 0, N + 1, A, T);
            st.update(1, 0, N + 1, B + 1, -T);
        }

        else {
            cout << euclidean(st.valueQuery(1, 0, N + 1, 0, A), st.GCDQuery(1, 0, N + 1, A + 1, B)) << '\n';
        }
    }
}