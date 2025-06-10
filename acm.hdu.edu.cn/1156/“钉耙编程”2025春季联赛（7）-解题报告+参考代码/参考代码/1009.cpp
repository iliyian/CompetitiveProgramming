#include <bits/stdc++.h>
using namespace std;
struct Node {
    int u, v, w;
};

struct DSU {
    vector<int> fa;
    vector<int> node;
    vector<int> edge;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        node.assign(n + 1, 1);
        edge.assign(n + 1, 0);
        return;
    }

    int find(int i) {
        if (fa[i] == i) return i;
        return fa[i] = find(fa[i]);
    }

    int unite(int i, int j) {
        int fi = find(i);
        int fj = find(j);
        if (fi != fj) {
            if (node[fi] < node[fj]) swap(fi, fj);

            fa[fj] = fi;
            node[fi] += node[fj];
            edge[fi] += edge[fj];
            return fi;
        }
        return fi;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;

    vector<Node> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }

    sort(a.begin(), a.end(), [](const Node &a, const Node &b) { return a.w > b.w; });

    DSU dsu(n);
    long long ans = 0;

    for (auto [u, v, w] : a) {
        int fu = dsu.find(u), fv = dsu.find(v);

        if (fu == fv) {
            if (dsu.edge[fu] < dsu.node[fu]) {
                ans += w;
                dsu.edge[fu]++;
            }
        } else {
            if (dsu.edge[fu] < dsu.node[fu] || dsu.edge[fv] < dsu.node[fv]) {
                ans += w;
                dsu.unite(u, v);
                dsu.edge[dsu.find(u)]++;
            }
        }
    }

    cout << ans << "\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
