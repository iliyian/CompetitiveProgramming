// date: 2023/12/10
// wa#010203: 线段树忘了开四倍大小......

#include <bits/stdc++.h>
#define N 100005
#define lc p << 1
#define rc p << 1 | 1
// #define int long long
using namespace std;

int dfn[N], top[N], pa[N], son[N], dep[N], siz[N], rnk[N], cnt = 0;
int a[N], d[N << 2], laz[N << 2], mod, n, m, r;

vector<vector<int>> g;

void dfs1(int u) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (dep[v]) continue;
    dep[v] = dep[u] + 1;
    pa[v] = u;
    dfs1(v);
    siz[u] += siz[v];
    if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
  }
}

void dfs2(int u, int t) {
  ++cnt;
  dfn[u] = cnt;
  rnk[cnt] = u;
  top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int v : g[u])
    if (v != pa[u] && v != son[u]) dfs2(v, v);
}

void pushup(int p) {
  d[p] = d[lc] + d[rc], d[p] %= mod;
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[rnk[s]];
    return;
  }
  int mid = s + (t - s >> 1);
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pushup(p);
}

void pushdown(int s, int t, int p) {
  int mid = s + (t - s >> 1);
  d[lc] += (mid - s + 1) % mod * laz[p] % mod, d[lc] %= mod,
  d[rc] += (t - mid) % mod * laz[p] % mod, d[rc] %= mod;
  laz[lc] += laz[p], laz[lc] %= mod,
  laz[rc] += laz[p], laz[rc] %= mod;
  laz[p] = 0;
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) {
    d[p] += (t - s + 1) % mod * c % mod, d[p] %= mod;
    laz[p] += c, laz[p] %= mod;
    return;
  }
  int mid = s + (t - s >> 1);
  pushdown(s, t, p);
  if (l <= mid) add(l, r, s, mid, lc, c);
  if (r > mid) add(l, r, mid + 1, t, rc, c);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p] % mod;
  int mid = s + (t - s >> 1), sum = 0;
  pushdown(s, t, p);
  if (l <= mid) sum += query(l, r, s, mid, lc), sum %= mod;
  if (r > mid) sum += query(l, r, mid + 1, t, rc), sum %= mod;
  return sum % mod;
}

void hldadd(int x, int y, int c) {
  c %= mod;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    add(dfn[top[x]], dfn[x], 1, n, 1, c);
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  add(dfn[x], dfn[y], 1, n, 1, c);
}

int hldquery(int x, int y) {
  int sum = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    sum += query(dfn[top[x]], dfn[x], 1, n, 1), sum %= mod;
    x = pa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  sum += query(dfn[x], dfn[y], 1, n, 1), sum %= mod;
  return sum % mod;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("J.in", "r", stdin);
  cin >> n >> m >> r >> mod;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dep[r] = 1;
  dfs1(r);
  dfs2(r, r);

  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int op, x, y, z;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> z;
      hldadd(x, y, z % mod);
    } else if (op == 2) {
      cin >> x >> y;
      cout << hldquery(x, y) << '\n';
    } else if (op == 3) {
      cin >> x >> z;
      add(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1, z % mod);
    } else {
      cin >> x;
      cout << query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1) << '\n';
    }
  }
}