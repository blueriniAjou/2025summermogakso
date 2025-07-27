#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int s;
    int e;
};

struct DisjointSet {
    vector<int> parent;
    vector<int> sz;
    vector<pair<int, int>> history;

    void init(int n) {
        parent.assign(n, 0);
        sz.assign(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        while (x != parent[x]) {
            x = parent[x];
        }

        return x;
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return;
        }

        if (sz[a] > sz[b]) {
            swap(a, b);
        }

        history.push_back({a, parent[a]});
        history.push_back({b, sz[b]});

        parent[a] = b;
        sz[b] += sz[a];
    }

    void rollback() {
        auto [b, szB] = history.back();
        history.pop_back();
        sz[b] = szB;

        auto [a, parentA] = history.back();
        history.pop_back();
        parent[a] = parentA;
    }
};

struct DivideConquer {
    vector<pair<int, int>> askQueries;
    vector<int> result;
    DisjointSet ds;

    DivideConquer(const int N, const int M) {
        askQueries.assign(M + 1, {0, 0});
        result.assign(M + 1, -1);
        ds.init(N + 1);
    }

    void solve(int node, int l, int r, const vector<Edge>& edges) {
        int sz = ds.history.size();
        int m = l + (r - l >> 1);
        vector<Edge> edgesLeft;
        vector<Edge> edgesRight;

        for (const Edge& edge : edges) {
            auto& [u, v, s, e] = edge;

            if (r < s || e < l) {
                continue;
            }

            if (s <= l && r <= e) {
                ds.unite(u, v);
            }
            
            else {
                if (s <= m && l <= e) {
                    edgesLeft.push_back(edge);
                }

                if (s <= r && m + 1 <= e) {
                    edgesRight.push_back(edge);
                }
            }
        }

        if (l == r) {
            if (askQueries[l].first) {
                result[l] = ds.find(askQueries[l].first) == ds.find(askQueries[l].second);
            }

            return;
        }

        solve(node << 1, l, m, edgesLeft);
        solve(node << 1 | 1, m + 1, r, edgesRight);

        while (ds.history.size() > sz) {
            ds.rollback();
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> updateQueries(N + 1, vector<pair<int, int>>());
    vector<Edge> edges;
    DivideConquer dc(N, M);

    for (int i = 1; i < M + 1; ++i) {
        int Q, A, B;
        cin >> Q >> A >> B;

        if (A > B) {
            swap(A, B);
        }

        if (Q == 1 || Q == 2) {
            updateQueries[A].push_back({B, i});
        }

        else {
            dc.askQueries[i] = {A, B};
        }
    }

    for (int i = 1; i < N + 1; ++i) {
        sort(updateQueries[i].begin(), updateQueries[i].end());

        for (int j = 0; j < updateQueries[i].size(); ++j) {
            if (j == updateQueries[i].size() - 1 || updateQueries[i][j].first != updateQueries[i][j + 1].first) {
                edges.push_back({i, updateQueries[i][j].first, updateQueries[i][j].second, M});
            }

            else {
                edges.push_back({i, updateQueries[i][j].first, updateQueries[i][j].second, updateQueries[i][j + 1].second - 1});
                ++j;
            }
        }
    }

    dc.solve(1, 1, M, edges);

    for (int i : dc.result) {
        if (i != -1) {
            cout << i << '\n';
        }
    }
}