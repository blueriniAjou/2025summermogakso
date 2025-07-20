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
 
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> planets(3, vector<pair<int, int>>(N, {0, 0}));
    vector<Edge> graph;
    graph.reserve(3 * N);

    for (int i = 0; i < N; ++i) {
        cin >> planets[0][i].first >> planets[1][i].first >> planets[2][i].first;

        planets[0][i].second = i;
        planets[1][i].second = i;
        planets[2][i].second = i;
    }

    for (int i = 0; i < 3; ++i) {
        sort(planets[i].begin(), planets[i].end());
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j < N; ++j) {
            graph.push_back(Edge(planets[i][j - 1].second, planets[i][j].second, planets[i][j].first - planets[i][j - 1].first));
        }
    }

    sort(graph.begin(), graph.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    DisjointSet ds(N);
    long long sum = 0;

    for (const Edge& e : graph) {
        auto& [u, v, w] = e;

        if (ds.find(u) != ds.find(v)) {
            sum += w;
            ds.unite(u, v);
        }
    }

    cout << sum;
}