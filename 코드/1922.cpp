#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.assign(n, 0);
        rank.assign(n, 0);

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
        int ra = find(a);
        int rb = find(b);

        if (ra == rb) {
            return;
        }

        if (rank[ra] < rank[rb]) {
            parent[ra] = rb;
        }

        else if (rank[ra] > rank[rb]) {
            parent[rb] = ra;
        }

        else {
            parent[ra] = rb;
            rank[rb]++;
        }
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int N, M;
    cin >> N >> M;

    vector<Edge> graph;
    graph.reserve(M);

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b) {
            continue;
        }

        graph.push_back(Edge(a, b, c));
    }

    sort(graph.begin(), graph.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    DisjointSet ds(N + 1);
    int sum = 0;

    for (const Edge& e : graph) {
        auto& [u, v, w] = e;

        if (ds.find(u) != ds.find(v)) {
            sum += w;
            ds.unite(u, v);
        }
    }

    cout << sum;
}