// date: 2024-03-19 20:33:37
// tag: 边权剖分
// wa#01: dep[top[x]]<dep[top[y]]后面的y写成x了，
// 取反的取反是不取反而不是强制取反，这个是取反而非修改
// re#02: 交上去删freopen的时候把cin>>n给删了，多删了一行

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N 200005
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

int dfn[N], rnk[N], siz[N], son[N], dep[N], top[N], pa[N], a[N];
int n, dfncnt = 0;
int oppo[N << 2], mn[N << 2], mx[N << 2], sm[N << 2];

void opposite(int p) {
  int m1 = mx[p], m2 = mn[p];
  mx[p] = -m2, mn[p] = -m1;
  sm[p] = -sm[p];
}

void pushdown(int p) {
  if (oppo[p]) {
    opposite(lc);
    opposite(rc);
    oppo[lc] ^= 1, oppo[rc] ^= 1;
    oppo[p] = 0;
  }
}

void pushup(int p) {
  mn[p] = min(mn[lc], mn[rc]);
  mx[p] = max(mx[lc], mx[rc]);
  sm[p] = sm[lc] + sm[rc];
}

void modify(int x, int c, int s, int t, int p) {
  if (x == s && x == t) {
    mx[p] = mn[p] = sm[p] = c;
    oppo[p] = 0;
    return;
  }
  int mid = (s + t) / 2;
  pushdown(p);
  if (x <= mid) modify(x, c, s, mid, lc);
  else modify(x, c, mid + 1, t, rc);
  pushup(p);
}

void oppositify(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) {
    opposite(p);
    oppo[p] ^= 1;
    return;
  }
  int mid = (s + t) / 2;
  pushdown(p);
  if (l <= mid) oppositify(l, r, s, mid, lc);
  if (r > mid) oppositify(l, r, mid + 1, t, rc);
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

int querymin(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return mn[p];
  int mid = (s + t) / 2, ans = INT_MAX;
  pushdown(p);
  if (l <= mid) ans = min(ans, querymin(l, r, s, mid, lc));
  if (r > mid) ans = min(ans, querymin(l, r, mid + 1, t, rc));
  return ans;
}

int querysum(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return sm[p];
  int mid = (s + t) / 2, ans = 0;
  pushdown(p);
  if (l <= mid) ans += querysum(l, r, s, mid, lc);
  if (r > mid) ans += querysum(l, r, mid + 1, t, rc);
  return ans;
}

void build(int l, int r, int p) {
  if (l == r) {
    mx[p] = mn[p] = sm[p] = a[rnk[l]];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

void dfs1(int u) {
  siz[u] = 1;
  for (auto [v, w] : g[u]) {
    if (dep[v]) continue;
    dep[v] = dep[u] + 1;
    pa[v] = u;
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

int hldquerymin(int x, int y) {
  int ans = INT_MAX;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = min(ans, querymin(dfn[top[x]], dfn[x], 1, n, 1));
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ans = min(ans, querymin(dfn[x] + 1, dfn[y], 1, n, 1));
  return ans;
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

int hldquerysum(int x, int y) {
  int ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans += querysum(dfn[top[x]], dfn[x], 1, n, 1);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ans += querysum(dfn[x] + 1, dfn[y], 1, n, 1);
  return ans;
}

void hldoppositify(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    oppositify(dfn[top[x]], dfn[x], 1, n, 1);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  oppositify(dfn[x] + 1, dfn[y], 1, n, 1);
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
    u++, v++;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    edges.push_back({u, v, w});
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);
  int q;
  cin >> q;
  for (int _ = 0; _ < q; _++) {
    string op;
    int x, y;
    cin >> op >> x >> y;
    x++, y++;
    if (op == "C") {
      x--, y--;
      auto [u, v, nil] = edges[x - 1];
      if (dep[u] > dep[v]) swap(u, v);
      modify(dfn[v], y, 1, n, 1);
    } else if (op == "N") {
      hldoppositify(x, y);
    } else if (op == "SUM") {
      cout << hldquerysum(x, y) << '\n';
    } else if (op == "MAX") {
      cout << hldquerymax(x, y) << '\n';
    } else {
      cout << hldquerymin(x, y) << '\n';
    }
  }

  return 0;
}