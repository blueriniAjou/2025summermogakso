#include <iostream>
#include <vector>
#include <list>
#include <limits>
using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> sz;
    list<pair<int, int>> history;

    DisjointSet(int n) {
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

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return false;
        }

        if (sz[a] > sz[b]) {
            swap(a, b);
        }

        history.push_back({a, parent[a]});
        history.push_back({b, sz[b]});

        parent[a] = b;
        sz[b] += sz[a];

        return true;
    }

    bool rollback() {
        if (history.size()) {
            auto [b, szB] = history.back();
            history.pop_back();
            sz[b] = szB;

            auto [a, parentA] = history.back();
            history.pop_back();
            parent[a] = parentA;

            return true;
        }

        return false;
    }
};

struct Edge {
    int u;
    int v;
    int w;
};

struct Context {
    const int N;
    const int M;
    const vector<int>& limits;
    const vector<Edge>& graph;
};

struct State {
    int result;
    int low;
    vector<int> degree;
    DisjointSet ds;
};

void backtracking(const Context& ctx, State& st, int curr, int bound, int sum, int vertexCnt, int edgeUsed) {
    if (curr == ctx.N - 1) {
        if (st.low > sum) {
            st.result = edgeUsed;
            st.low = sum;
        }

        return;
    }

    for (int i = bound; i < ctx.M; ++i) {
        if (st.ds.find(ctx.graph[i].u) == st.ds.find(ctx.graph[i].v)) {
            continue;
        }

        if ((st.degree[ctx.graph[i].u] == ctx.limits[ctx.graph[i].u]) || (st.degree[ctx.graph[i].v] == ctx.limits[ctx.graph[i].v])) {
            continue;
        }

        int flag = st.ds.unite(ctx.graph[i].u, ctx.graph[i].v);

        ++st.degree[ctx.graph[i].u];
        ++st.degree[ctx.graph[i].v];
        sum += ctx.graph[i].w;
        edgeUsed |= 1 << i;

        backtracking(ctx, st, curr + 1, i + 1, sum, vertexCnt, edgeUsed);

        if (flag) {
            st.ds.rollback();
        }

        --st.degree[ctx.graph[i].u];
        --st.degree[ctx.graph[i].v];
        sum -= ctx.graph[i].w;
        edgeUsed &= ~(1 << i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> limits(N + 1, 0);
    vector<Edge> graph;
    graph.reserve(M);

    for (int i = 1; i < N + 1; ++i) {
        cin >> limits[i];
    }

    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;

        graph.push_back(Edge{A, B, C});
    }

    Context ctx{N, M, limits, graph};
    State st{0, numeric_limits<int>::max(), vector<int>(N + 1, 0), DisjointSet(N + 1)};

    backtracking(ctx, st, 0, 0, 0, 0, 0);

    if (st.low < numeric_limits<int>::max()) {
        cout << "YES" << '\n';

        for (int i = 0; i < M; ++i) {
            if (st.result & (1 << i)) {
                cout << graph[i].u << ' ' << graph[i].v << '\n';
            }
        }
    }

    else {
        cout << "NO";
    }
}