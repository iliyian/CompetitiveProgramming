#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, m;
vector<pair<int, int>> G[N];
int a[N];

int dfn[N], low[N], idx;
bool is_bridge[N];
void tarjan(int u, int prev) {
    dfn[u] = low[u] = ++idx;
    for (auto [v, id] : G[u]) {
        if (id == prev) continue;
        if (!dfn[v]) {
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) is_bridge[id] = true;
        } else
            low[u] = min(low[u], dfn[v]);
    }
    return;
}
int fa[N], siz[N];
int getf(int v) {
    if (fa[v] == v) return v;
    return fa[v] = getf(fa[v]);
}

void merge(int u, int v) {
    int fu = getf(u), fv = getf(v);
    if (fu != fv) fa[fu] = fv, siz[fv] += siz[fu];
    return;
}
vector<int> E[N];
bool book[N];
void init(int u, int father) {
    if (siz[u] > 1) book[u] = true;
    for (int v : E[u]) {
        if (v == father) continue;
        init(v, u);
        if (book[v]) {
            book[u] = true;
            merge(u, v);
        }
    }
    return;
}
long long sum[N], mx[N];
long long ans;
void dfs1(int u, int father) {
    mx[u] = sum[u];
    for (int v : E[u]) {
        if (v == father) continue;
        dfs1(v, u);
        ans = max(ans, mx[u] + mx[v]);
        mx[u] = max(mx[u], mx[v] + sum[u]);
    }
    ans = max(ans, mx[u]);
    return;
}
long long pre[N];

void dfs2(int u, int father) {
    pre[u] = pre[father] + sum[u];
    mx[u] = sum[u];
    for (int v : E[u]) {
        if (v == father) continue;
        dfs2(v, u);
        ans = max(ans, mx[u] + mx[v] + pre[father]);
        mx[u] = max(mx[u], mx[v] + sum[u]);
    }
    return;
}
void solve() {
    cin >> n >> m;
    assert(1 <= n <= 2e5);
    assert(n - 1 <= m <= 2e5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        G[x].emplace_back(y, i);
        G[y].emplace_back(x, i);
    }
    idx = 0;
    fill(dfn + 1, dfn + n + 1, 0);
    fill(low + 1, low + n + 1, 0);
    fill(is_bridge + 1, is_bridge + m + 1, false);
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, 0);
    for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for (int u = 1; u <= n; u++)
        for (auto [v, id] : G[u])
            if (u < v)
                if (!is_bridge[id]) merge(u, v);
    for (int i = 1; i <= n; i++) E[i].clear();
    for (int u = 1; u <= n; u++)
        for (auto [v, id] : G[u])
            if (u < v)
                if (is_bridge[id]) {
                    int x = getf(u), y = getf(v);
                    assert(x != y);
                    E[x].push_back(y);
                    E[y].push_back(x);
                }
    int root = 1;
    for (int i = 1; i <= n; i++) {
        int v = getf(i);
        if (siz[v] > 1) root = v;
    }
    fill(book + 1, book + n + 1, false);
    init(root, 0);
    fill(sum + 1, sum + n + 1, 0);
    for (int i = 1; i <= n; i++) sum[getf(i)] += a[i];
    for (int i = 1; i <= n; i++) E[i].clear();
    for (int u = 1; u <= n; u++)
        for (auto [v, id] : G[u])
            if (u < v) {
                int x = getf(u), y = getf(v);
                if (x == y) continue;
                E[x].push_back(y);
                E[y].push_back(x);
            }
    root = getf(root);
    ans = 0;
    dfs1(root, 0);
    if (siz[root] > 1) dfs2(root, 0);
    cout << ans << "\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
