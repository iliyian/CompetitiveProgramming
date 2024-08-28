// date: 2024-08-25 21:28:20
// tag: heavy light decomposition with segment tree handling single point modify and range query

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

constexpr int N = 1e5;

std::vector<int> g[N + 1];
std::vector<int> rnk(N + 1), dfn(N + 1), top(N + 1), son(N + 1), pa(N + 1), dep(N + 1), siz(N + 1);
std::vector<int> d(N << 2);
int dfncnt = 0;

void dfs1(int u) {
  siz[u] = 1;
  for (int v : g[u]) {
    if (!dep[v]) {
      pa[v] = u;
      dep[v] = dep[u] + 1;
      dfs1(v);
      siz[u] += siz[v];
      if (siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
  }
}

void dfs2(int u, int t) {
  dfn[u] = ++dfncnt;
  rnk[dfncnt] = u;
  top[u] = t;
  if (!son[u]) {
    return;
  }
  dfs2(son[u], t);
  for (int v : g[u]) {
    if (v != son[u] && v != pa[u]) {
      dfs2(v, v);
    }
  }
}

void pull(int p) {
  d[p] = d[lc] + d[rc];
}

void modify(int x, int s, int t, int p, int c) {
  if (x > t || x < s) return;
  if (x == s && x == t) {
    d[p] = c;
    return;
  }
  modify(x, s, mid, lc, c);
  modify(x, mid + 1, t, rc, c);
  pull(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) {
    return d[p];
  }
  return query(l, r, s, mid, lc) + query(l, r, mid + 1, t, rc);
}

int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    x = pa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> edges(n);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    edges[i] = {x, y};
  }
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x;
      x = dep[edges[x].first] > dep[edges[x].second] ? edges[x].first : edges[x].second;
      modify(dfn[x], 1, n, 1, 0);
    } else if (op == 2) {
      std::cin >> x;
      x = dep[edges[x].first] > dep[edges[x].second] ? edges[x].first : edges[x].second;
      modify(dfn[x], 1, n, 1, 1);
    } else {
      std::cin >> x >> y;
      int xy = lca(x, y), sum = 0;
      int len = dep[x] + dep[y] - 2 * dep[xy];
      while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
        sum += query(dfn[top[x]], dfn[x], 1, n, 1);
        x = pa[top[x]];
      }
      if (dep[x] > dep[y]) std::swap(x, y);
      sum += query(dfn[x] + 1, dfn[y], 1, n, 1);
      std::cout << (sum ? -1 : len) << '\n';
    }
  }

  return 0;
}