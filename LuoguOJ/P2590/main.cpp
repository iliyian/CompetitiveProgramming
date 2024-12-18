// date: 2024-03-18 22:03:36
// tag: 树链剖分

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N 300005
using namespace std;

vector<vector<int>> g;
int a[N], dep[N], top[N], rnk[N], son[N], pa[N], siz[N], dfn[N];
int mx[N << 2], sm[N];
int dfncnt = 0, n;

void dfs1(int u) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (v == pa[u]) continue;
    pa[v] = u;
    dep[v] = dep[u] + 1;
    dfs1(v);
    siz[u] += siz[v];
    if (!son[u] || siz[v] > siz[son[u]]) {
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
  for (int v : g[u]) {
    if (v != pa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

void pushup(int p) {
  mx[p] = max(mx[lc], mx[rc]);
  sm[p] = sm[lc] + sm[rc];
}

void build(int l, int r, int p) {
  if (l == r) {
    mx[p] = sm[p] = a[rnk[l]];
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
  if (l <= mid) ans = max(ans, querymax(l, r, s, mid, lc));
  if (r > mid) ans = max(ans, querymax(l, r, mid + 1, t, rc));
  return ans;
}

int querysum(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return sm[p];
  int mid = (s + t) / 2, ans = 0;
  if (l <= mid) ans += querysum(l, r, s, mid, lc);
  if (r > mid) ans += querysum(l, r, mid + 1, t, rc);
  return ans;
}

void modify(int x, int c, int s, int t, int p) {
  if (x == s && x == t) {
    mx[p] = sm[p] = c;
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modify(x, c, s, mid, lc);
  else modify(x, c, mid + 1, t, rc);
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
  ans = max(ans, querymax(dfn[x], dfn[y], 1, n, 1));
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
  ans += querysum(dfn[x], dfn[y], 1, n, 1);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);

  int q;
  cin >> q;

  for (int _ = 0; _ < q; _++) {
    string op;
    int u, v;
    cin >> op >> u >> v;
    if (op == "CHANGE") {
      modify(dfn[u], v, 1, n, 1);
    } else if (op == "QMAX") {
      cout << hldquerymax(u, v) << '\n';
    } else {
      cout << hldquerysum(u, v) << '\n';
    }
  }
  return 0;
}