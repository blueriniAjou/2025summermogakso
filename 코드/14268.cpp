#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
    vector<int> tree;

    SegmentTree(const vector<int>& v) {
        int size = 1;

        while (size < v.size()) {
            size <<= 1;
        }

        tree.assign(size << 1, 0);
        build(v, 1, 0, v.size() - 1);
    }

    void build(const vector<int>& v, int node, int l, int r) {
        if (l == r) {
            tree[node] = v[l];
            return;
        }

        int m = l + (r - l >> 1);

        build(v, node << 1, l, m);
        build(v, node << 1 | 1, m + 1, r);

        tree[node] = tree[node << 1] + tree[node << 1 | 1]; 
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) {
            return 0;
        }

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int m = l + (r - l >> 1);

        return query(node << 1, l, m, ql, qr) + query(node << 1 | 1, m + 1, r, ql, qr);
    }

    void update(int node, int l, int r, int index, int value) {
        if (index < l || r < index) {
            return;
        }

        if (l == r) {
            tree[node] += value;
            return;
        }

        int m = l + (r - l >> 1);

        update(node << 1, l, m, index, value);
        update(node << 1 | 1, m + 1, r, index, value);

        tree[node] = tree[node << 1] + tree[node << 1 | 1]; 
    }
};

void dfs(const vector<vector<int>>& graph, vector<pair<int, int>>& range, int& cnt, int curr) {
    range[curr].first = ++cnt;

    for (int child : graph[curr]) {
        dfs(graph, range, cnt, child);
    }

    range[curr].second = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>());
    vector<pair<int, int>> range(N + 1, {0, 0});

    for (int i = 1; i < N + 1; ++i) {
        int parent;
        cin >> parent;

        if (parent != -1) {
            graph[parent].push_back(i);
        }
    }

    int cnt = 0;
    dfs(graph, range, cnt, 1);

    SegmentTree st(vector<int>(N + 2, 0));

    for (int i = 0; i < M; ++i) {
        int query;
        cin >> query;

        if (query == 1) {
            int empl, w;
            cin >> empl >> w;

            st.update(1, 0, N + 1, range[empl].first, w);
            st.update(1, 0, N + 1, range[empl].second + 1, -w);
        }

        if (query == 2) {
            int empl;
            cin >> empl;

            cout << st.query(1, 0, N + 1, 1, range[empl].first) << '\n';
        }
    }
}