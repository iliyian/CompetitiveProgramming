#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define int long long
#define mid (s + t) / 2

constexpr int N = 8005;

int a[N], dep[N], siz[N], pa[N], son[N], dfn[N], rnk[N], top[N], cnt = 0;
int d[N << 2], laz[N << 2], n, m;

constexpr int mod = 1e9 + 7;

std::vector<std::vector<int>> g(N + 1);

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
  d[p] = d[lc] + d[rc];
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[rnk[s]];
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return d[p];
  return (query(l, r, s, mid, lc) + query(l, r, mid + 1, t, rc)) % mod;
}

void modify(int x, int s, int t, int p, int c) {
  if (x > t || x < s) return;
  if (s == t) {
    d[p] = c;
    return;
  }
  modify(x, s, mid, lc, c);
  modify(x, mid + 1, t, rc, c);
  pushup(p);
}

signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i];
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  build(1, n, 1);
  int q;
  std::cin >> q;
  int ans = 0, k = 0;
  for (int i = 1; i <= q; i++) {
    char op;
    std::cin >> op;
    if (op == 'Q') {
      int x;
      std::cin >> x;
      int cur = query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1);
      std::cerr << cur << '\n';
      ans += k * cur % mod;
    } else {
      int x, c;
      std::cin >> x >> c;
      modify(dfn[x], 1, n, 1, c);
    }
  }
  std::cout << ans << '\n';
  return 0;
}