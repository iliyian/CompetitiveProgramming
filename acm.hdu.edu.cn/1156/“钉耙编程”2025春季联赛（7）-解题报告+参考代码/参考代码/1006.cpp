#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, inf = 1e9;
int p[N], a[N], head[N], level[N], cur[N], Q[N], s, t;
int n, m, k, tot;
struct Edge{
    int vet, nxt, f;
} E[N << 5];
void add(int u, int v, int f) {
    E[++tot] = {v, head[u], f}, head[u] = tot;
    E[++tot] = {u, head[v], 0}, head[v] = tot;
}
int calc(int i, int j) {
    return (i - 1) * m + j;
}
bool bfs() {
    memset(level, 0, sizeof(int) * (t + 1));
    int cnt;
    level[Q[cnt = 1] = s] = 1;
    for (int top = 1; top <= cnt; ++top) {
        int u = Q[top];
        for (int i = head[u]; i; i = E[i].nxt) {
            int v = E[i].vet;
            if (!E[i].f || level[v]) continue;
            Q[++cnt] = v;
            level[v] = level[u] + 1;
        }
    }
    return !!level[t];
}
int dfs(int u, int limit) {
    if (u == t || !limit) return limit;
    int res = 0;
    for (int &i = cur[u]; i; i = E[i].nxt) {
        int v = E[i].vet;
        if (!E[i].f || level[v] != level[u] + 1) continue;
        int tmp = dfs(v, min(limit, E[i].f));
        res += tmp, limit -= tmp;
        E[i].f -= tmp, E[i ^ 1].f += tmp;
        if (!limit) break;
    }
    return res;
}
int dinic() {
    int res = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof(int) * (t + 1));
        res += dfs(s, inf);
    }
    return res;
}
int id(int x, int y) {
    return (x - 1) * m + y;
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[id(i, j)];
    s = 0, t = n * m + 1;
    tot = 1;
    memset(head, 0, sizeof(int) * (t + 1));
    for (int i = 1; i <= n; ++i)
        add(s, id(i, 1), a[id(i, 1)]);
    for (int i = 1; i <= n; ++i)
        for (int j = 2; j <= m; ++j)
            add(id(i, j - 1), id(i, j), a[id(i, j)]);
    for (int i = 1; i <= n; ++i)
        add(id(i, m), t, inf);
    while (k--) {
        int u, v, d;
        cin >> u >> v >> d;
        for (int i = 1; i < m; ++i) {
            int j = i + 1;
            while (j <= m && p[j] - p[i] <= d) j++;
            if (j <= m) {
                j--;
                add(id(u, j), id(v, i), inf);
                add(id(v, j), id(u, i), inf);
            }
        }
    }
    int ans = dinic();
    cout << ans << endl;
}
int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}