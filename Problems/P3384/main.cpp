// date: 2023/12/5
// tag: seg, hld,
// wa#01, wa#02, wa#03: 好事多模

#include <bits/stdc++.h>
#define int long long
#define N 100005
#define ls(p) p << 1
#define rs(p) p << 1 | 1
using namespace std;

int mod, a[N], dep[N], siz[N], pa[N], son[N], dfn[N], rnk[N], top[N], cnt = 0;
int d[N << 2], laz[N << 2], n, m, r;

vector<vector<int>> g;

void dfs1(int u) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (dep[v]) continue;
    dep[v] = dep[u] + 1;
    dfs1(v);
    pa[v] = u;
    siz[u] += siz[v];
    if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
  }
}

void dfs2(int u, int t) {
  top[u] = t;
  ++cnt;
  dfn[u] = cnt;
  rnk[cnt] = u;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int v : g[u])
    if (son[u] != v && pa[u] != v)
      dfs2(v, v);
}

void pushup(int p) {
  d[p] = d[ls(p)] + d[rs(p)];
}

void build(int l, int r, int p) {
  if (l == r) {
    // rnk[dfn[x]] = x;
    // seg operates dfn, it gets the real x;
    d[p] = a[rnk[l]];
    return;
  }
  int mid = l + (r - l >> 1);
  build(l, mid, ls(p));
  build(mid + 1, r, rs(p));
  pushup(p);
}

void pushdown(int s, int t, int p) {
  int mid = s + (t - s >> 1);
  d[ls(p)] = (d[ls(p)] + (mid - s + 1) % mod * laz[p] % mod) % mod;
  d[rs(p)] = (d[rs(p)] + (t - mid) % mod * laz[p] % mod) % mod;
  laz[ls(p)] = (laz[ls(p)] + laz[p]) % mod,
  laz[rs(p)] = (laz[rs(p)] + laz[p]) % mod;
  laz[p] = 0;
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int mid = s + (t - s >> 1), sum = 0;
  pushdown(s, t, p);
  if (l <= mid) sum += query(l, r, s, mid, ls(p)), sum %= mod;
  if (r > mid) sum += query(l, r, mid + 1, t, rs(p)), sum %= mod;
  return sum;
}

void add(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) {
    d[p] = (d[p] + (t - s + 1) % mod * c % mod) % mod,
    laz[p] = (laz[p] + c) % mod;
    return;
  }
  int mid = s + (t - s >> 1);
  pushdown(s, t, p);
  if (l <= mid) add(l, r, s, mid, ls(p), c);
  if (r > mid) add(l, r, mid + 1, t, rs(p), c);
  pushup(p);
}

void hldadd(int x, int y, int c) {
  c %= mod;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    add(dfn[top[x]], dfn[x], 1, n, 1, c);
    x = pa[top[x]];
  };
  if (dep[x] > dep[y]) swap(x, y);
  add(dfn[x], dfn[y], 1, n, 1, c);
}

int hldquery(int x, int y) {
  int sum = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    sum = (sum + query(dfn[top[x]], dfn[x], 1, n, 1) % mod) % mod;
    x = pa[top[x]];
  };
  if (dep[x] > dep[y]) swap(x, y);
  sum = (sum + query(dfn[x], dfn[y], 1, n, 1) % mod) % mod;
  return sum;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m >> r >> mod;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dep[r] = 1;
  dfs1(r);
  dfs2(r, r);
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int op, x, y, c;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> c;
      hldadd(x, y, c);
    } else if (op == 2) {
      cin >> x >> y;
      cout << hldquery(x, y) % mod << '\n';
    } else if (op == 3) {
      cin >> x >> c;
      add(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1, c);
    } else {
      cin >> x;
      cout << query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1) % mod << '\n';
    }
  }
}