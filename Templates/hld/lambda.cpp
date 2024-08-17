// date: 2024-08-12 16:43:03
// tag: hld+seg

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> dep(n + 1), siz(n + 1), pa(n + 1), son(n + 1), dfn(n + 1), rnk(n + 1), top(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    x++, y++;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto dfs1 = [&](auto self, int u) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (!dep[v]) {
        dep[v] = dep[u] + 1;
        pa[v] = u;
        self(self, v);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) {
          son[u] = v;
        }
      }
    }
  };
  int dfncnt = 0;
  auto dfs2 = [&](auto self, int u, int t) -> void {
    dfn[u] = ++dfncnt;
    rnk[dfncnt] = u;
    top[u] = t;
    if (!son[u]) return;
    self(self, son[u], t);
    for (int v : g[u]) {
      if (v != pa[u] && v != son[u]) {
        self(self, v, v);
      }
    }
  };
  dep[1] = 1;
  dfs1(dfs1, 1);
  dfs2(dfs2, 1, 1);
  std::vector<int> d(n << 2), laz(n << 2);
  auto pushup = [&](int p) {
    d[p] = d[lc] + d[rc];
  };
  auto pushdown = [&](int s, int t, int p) {
    d[lc] += (mid - s + 1) * laz[p], laz[lc] += laz[p];
    d[rc] += (t - mid) * laz[p], laz[rc] += laz[p];
    laz[p] = 0;
  };
  auto add = [&](auto self, int l, int r, int s, int t, int p, int c) -> void {
    if (l <= s && t <= r) {
      d[p] += (t - s + 1) * c;
      laz[p] += c;
      return;
    }
    pushdown(s, t, p);
    if (l <= mid) self(self, l, r, s, mid, lc, c);
    if (r > mid) self(self, l, r, mid + 1, t, rc, c);
    pushup(p);
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return 0;
    if (l <= s && t <= r) {
      return d[p];
    }
    pushdown(s, t, p);
    return self(self, l, r, s, mid, lc) + self(self, l, r, mid + 1, t, rc);
  };
  auto hldadd = [&](int x, int y, int c) {
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
      add(add, dfn[top[x]], dfn[x], 1, n, 1, c);
      x = pa[top[x]];
    }
    if (dep[x] > dep[y]) std::swap(x, y);
    add(add, dfn[x], dfn[y], 1, n, 1,  c);
  };
  int q;
  std::cin >> q;
  while (q--) {
    char op;
    std::cin >> op;
    if (op == 'A') {
      int x, y, d;
      std::cin >> x >> y >> d;
      x++, y++;
      hldadd(x, y, d);
    } else {
      int x;
      std::cin >> x;
      x++;
      std::cout << query(query, dfn[x], dfn[x] + siz[x] - 1, 1, n, 1) << '\n';
    }
  }


  return 0;
}