// date: 2024/02/05 20:00:28
// tag: wa#01: 没有考虑为森林的情况，即只给出了1这一个入口，应该在多个入口dfs
// wa#02: 并查集find(u)写成u了
// 最大生成树：求路径最小边的最大值，则最小生成树可求路径最大边最小值

#include <bits/stdc++.h>
#define N 10005
#define lc p << 1
#define rc p << 1 | 1
#define inf 0x3f3f3f3f
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

struct Ed {
  int u, v, w;
  bool operator < (const Ed &b) {
    return w > b.w;
  }
};

int id[N], in[N];

int find(int u) {return u == id[u] ? u : id[u] = find(id[u]);}
int dfn[N], rnk[N], a[N], dep[N], siz[N], son[N], pa[N], top[N], cnt = 0;
int d[N << 2], n, m, dfncnt = 0;

void dfs1(int u, int prv) {
  pa[u] = prv;
  siz[u] = 1;
  for (auto [v, w] : g[u]) {
    if (v == prv) continue;
    dep[v] = dep[u] + 1;
    a[v] = w;
    dfs1(v, u);
    siz[u] += siz[v];
    if (!son[u] || siz[v] > siz[son[u]])
      son[u] = v;
  }
}

void dfs2(int u, int t) {
  ++dfncnt;
  dfn[u] = dfncnt;
  rnk[dfncnt] = u;
  top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (auto [v, w] : g[u])
    if (v != son[u] && v != pa[u])
      dfs2(v, v);
}

void build(int l, int r, int p) {
  if (l == r) {
    d[p] = a[rnk[l]];
    return;
  }
  int mid = l + (r - l >> 1);
  build(l, mid, lc);
  build(mid + 1, r, rc);
  d[p] = min(d[lc], d[rc]);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int ans = 0x3f3f3f3f, mid = s + (t - s >> 1);
  if (l <= mid) ans = min(ans, query(l, r, s, mid, lc));
  if (r > mid) ans = min(ans, query(l, r, mid + 1, t, rc));
  return ans;
}

int hldquery(int u, int v) {
  int ans = inf;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    ans = min(ans, query(dfn[top[u]], dfn[u], 1, dfncnt, 1));
    u = pa[top[u]];
  }
  if (dep[u] > dep[v]) swap(u, v);
  ans = min(ans, query(dfn[u] + 1, dfn[v], 1, dfncnt, 1));
  return ans;
}

void solve() {
  cin >> n >> m;
  vector<Ed> edges;
  g.resize(n + 2);
  iota(id + 1, id + 1 + n, 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  sort(edges.begin(), edges.end());
  int cnt = 0;
  for (int i = 0; i < edges.size(); i++) {
    Ed ed = edges[i];
    int u = ed.u, v = ed.v, w = ed.w;
    if (cnt == n - 1) break;
    if (find(u) != find(v)) {
      id[find(u)] = find(v);
      cnt++;
      g[u].push_back({v, w}), g[v].push_back({u, w});
      // in[v]++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!siz[i])
      dfs1(i, 0);
  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      dfs2(i, i);
  build(1, dfncnt, 1); // n + 1 == dfncnt
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    // int ans = hldquery(u, v);
    // cout << (ans == inf ? -1 : ans) << '\n';
    if (find(u) != find(v))
      cout << -1 << '\n';
    else
      cout << hldquery(u, v) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}