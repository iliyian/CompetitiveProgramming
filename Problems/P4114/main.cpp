// date: 2024-03-19 19:04:41
// tag: 边权树剖
// wa#01: dfn和节点编号用混
// wa#02: a==b输出0而非INT_MIN

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N 300005
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;
int dfn[N], rnk[N], pa[N], top[N], son[N], dep[N], a[N], siz[N];
int dfncnt = 0, n;
int mx[N << 2];

void dfs1(int u) {
  siz[u] = 1;
  for (auto [v, w] : g[u]) {
    if (dep[v]) continue;
    dep[v] = dep[u] + 1;
    pa[v] = u;
    a[v] = w;
    dfs1(v);
    siz[v] += siz[u];
    if (siz[v] > siz[son[u]]) {
      son[u] = v;
    }
  }
}

void dfs2(int u, int t) {
  top[u] = t;
  dfn[u] = ++dfncnt;
  rnk[dfncnt] = u;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (auto [v, w] : g[u]) {
    if (v != pa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

void pushup(int p) {
  mx[p] = max(mx[lc], mx[rc]);
}

void build(int l, int r, int p) {
  if (l == r) {
    mx[p] = a[rnk[l]];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

void modify(int s, int t, int p, int x, int c) {
  if (s == t && x == s) {
    mx[p] = c;
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modify(s, mid, lc, x, c);
  else modify(mid + 1, t, rc, x, c);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return mx[p];
  int mid = (s + t) / 2, ans = 0;
  if (l <= mid) ans = max(ans, query(l, r, s, mid, lc));
  if (r > mid) ans = max(ans, query(l, r, mid + 1, t, rc));
  return ans;
}

int hldquery(int x, int y) {
  int ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = max(ans, query(dfn[top[x]], dfn[x], 1, n, 1));
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ans = max(ans, query(dfn[x] + 1, dfn[y], 1, n, 1));
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  cin >> n;
  vector<tuple<int, int, int>> edges;
  g.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);
  string op;
  while (cin >> op) {
    if (op == "DONE") break;
    if (op == "QUERY") {
      int x, y;
      cin >> x >> y;
      cout << hldquery(x, y) << '\n';
    } else {
      int x, w;
      cin >> x >> w;
      auto [u, v, nil] = edges[x - 1];
      if (dep[u] < dep[v]) swap(u, v);
      modify(1, n, 1, dfn[u], w);
    }
  }
  return 0;
}