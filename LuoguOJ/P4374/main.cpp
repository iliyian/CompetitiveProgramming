// date: 2024-08-25 20:51:55
// tag: hld维护路径，区间改seg，RMQ

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

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }

  std::vector<int> id(n + 1);
  std::vector<int> siz(n + 1), pa(n + 1), rnk(n + 1), dfn(n + 1), son(n + 1), dep(n + 1), top(n + 1);
  auto dfs1 = [&](auto self, int u) -> void {
    siz[u] = 1;
    for (auto [v, i] : g[u]) {
      if (!dep[v]) {
        pa[v] = u;
        id[v] = i;
        dep[v] = dep[u] + 1;
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
    if (!son[u]) {
      return;
    }
    self(self, son[u], t);
    for (auto [v, _] : g[u]) {
      if (v != pa[u] && v != son[u]) {
        self(self, v, v);
      }
    }
  };
  dep[1] = 1;
  dfs1(dfs1, 1);
  dfs2(dfs2, 1, 1);

  std::vector<int> laz(n << 2, INT_MAX), mn(n << 2, INT_MAX);

  auto exec = [&](int p, int c) {
    laz[p] = std::min(laz[p], c);
    mn[p] = std::min(mn[p], c);
  };

  auto pushdown = [&](int p) {
    if (laz[p] != INT_MAX) {
      exec(lc, laz[p]);
      exec(rc, laz[p]);
      laz[p] = INT_MAX;
    }
  };

  auto modify = [&](auto self, int l, int r, int s, int t, int p, int c) -> void {
    if (l > t || r < s || l > r) return;
    if (l <= s && t <= r) {
      exec(p, c);
      return;
    }
    pushdown(p);
    self(self, l, r, s, mid, lc, c);
    self(self, l, r, mid + 1, t, rc, c);
  };

  auto query = [&](auto self, int x, int s, int t, int p) -> int {
    if (x > t || x < s) return INT_MAX;
    if (x == s && x == t) {
      return mn[p];
    }
    pushdown(p);
    return std::min(self(self, x, s, mid, lc), self(self, x, mid + 1, t, rc));
  };

  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
      modify(modify, dfn[top[x]], dfn[x], 1, n, 1, w); // 必定不同链
      x = pa[top[x]];
    }
    if (dep[x] > dep[y]) std::swap(x, y);
    modify(modify, dfn[x] + 1, dfn[y], 1, n, 1, w);
  }
  std::vector<int> ans(n + 1);
  for (int i = 2; i <= n; i++) {
    ans[id[rnk[i]]] = query(query, i, 1, n, 1);
  }
  for (int i = 1; i <= n - 1; i++) {
    std::cout << (ans[i] == INT_MAX ? -1 : ans[i]) << '\n';
  }

  return 0;
}