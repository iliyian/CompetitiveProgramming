#include <bits/stdc++.h>
#define int long long
#define N 100005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;
int mx[N << 2], ad[N << 2], mo[N << 2];
int dfn[N], rnk[N], top[N], pa[N], son[N], siz[N], dep[N], a[N];
int dfncnt = 0, n;

void dfs1(int u) {
  siz[u] = 1;
  for (auto [v, w] : g[u]) {
    if (dep[v]) continue;
    pa[v] = u;
    dep[v] = dep[u] + 1;
    a[v] = w;
    dfs1(v);
    siz[u] += siz[v];
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

void pushdown(int p) {
  if (mo[p] >= 0) {
    ad[lc] = ad[rc] = 0;
    mx[lc] = mx[rc] = mo[lc] = mo[rc] = mo[p];
    mo[p] = -1;
  }
  if (ad[p]) {
    ad[lc] += ad[p], ad[rc] += ad[p];
    mx[lc] += ad[p], mx[rc] += ad[p];
    ad[p] = 0;
  }
}

void build(int l, int r, int p) {
  mo[p] = -1;
  if (l == r) {
    mx[p] = a[rnk[l]];
    ad[p] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

int querymax(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return mx[p];
  int mid = (s + t) / 2, ans = INT_MIN;
  pushdown(p);
  if (l <= mid) ans = max(ans, querymax(l, r, s, mid, lc));
  if (r > mid) ans = max(ans, querymax(l, r, mid + 1, t, rc));
  return ans;
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l > r) return;
  if (l <= s && t <= r) {
    ad[p] += c;
    mx[p] += c;
    return;
  };
  int mid = (s + t) / 2;
  pushdown(p);
  if (l <= mid) add(l, r, s, mid, lc, c);
  if (r > mid) add(l, r, mid + 1, t, rc, c);
  pushup(p);
}

void modify(int l, int r, int s, int t, int p, int c) {
  if (l > r) return;
  if (l <= s && t <= r) {
    mo[p] = c;
    mx[p] = c;
    ad[p] = 0;
    return;
  }
  int mid = (s + t) / 2;
  pushdown(p);
  if (l <= mid) modify(l, r, s, mid, lc, c);
  if (r > mid) modify(l, r, mid + 1, t, rc, c);
  pushup(p);
}

int hldquerymax(int x, int y) {
  int ans = INT_MIN;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = max(ans, querymax(dfn[top[x]], dfn[x], 1, n, 1));
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ans = max(ans, querymax(dfn[x] + 1, dfn[y], 1, n, 1));
  return ans;
}

void hldadd(int x, int y, int c) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    add(dfn[top[x]], dfn[x], 1, n, 1, c);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  add(dfn[x] + 1, dfn[y], 1, n, 1, c);
}

void hldmodify(int x, int y, int c) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    modify(dfn[top[x]], dfn[x], 1, n, 1, c);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  modify(dfn[x] + 1, dfn[y], 1, n, 1, c);
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
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    edges.push_back({u, v, w});
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);
  string op;
  while (cin >> op) {
    if (op == "Stop") break;
    if (op == "Max") {
      int u, v;
      cin >> u >> v;
      cout << hldquerymax(u, v) << '\n';
    } else if (op == "Cover") {
      int u, v, w;
      cin >> u >> v >> w;
      hldmodify(u, v, w);
    } else if (op == "Add") {
      int u, v, w;
      cin >> u >> v >> w;
      hldadd(u, v, w);
    } else {
      int k, w;
      cin >> k >> w;
      auto [u, v, nil] = edges[k - 1];

      hldmodify(u, v, w);
    }
  }

  return 0;
}