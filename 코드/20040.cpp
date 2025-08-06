#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> sz;

    DisjointSet(int n) {
        parent.assign(n, 0);
        sz.assign(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
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

        parent[a] = b;
        sz[b] += sz[a];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    DisjointSet ds(N);

    for (int i = 1; i < M + 1; ++i) {
        int a, b;
        cin >> a >> b;

        if (ds.find(a) == ds.find(b)) {
            cout << i;
            return 0;
        }

        ds.unite(a, b);
    }

    cout << 0;
}