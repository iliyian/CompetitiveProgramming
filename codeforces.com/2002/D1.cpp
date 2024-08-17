// date: 2024-08-12 12:54:21
// tag: dfs的性质

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> dep(n + 1), siz(n + 1), top(n + 1), pa(n + 1), dfn(n + 1), rnk(n + 1), son(n + 1);
  int dfncnt = 0;
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
  auto dfs2 = [&](auto self, int u, int t) -> void {
    dfn[u] = ++dfncnt;
    rnk[dfncnt] = u;
    top[u] = t;
    if (!son[u]) {
      return;
    }
    self(self, son[u], t);
    for (int v : g[u]) {
      if (v != pa[u] && v != son[u]) {
        self(self, v, v);
      }
    }
  };
  auto isAncestor = [&](int p, int x) {
    if (!p) return false;
    if (dep[p] > dep[x]) return false;
    while (dep[pa[top[x]]] >= dep[p]) {
      x = pa[top[x]];
    }
    return top[p] == top[x];
  };
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  dep[1] = 1;
  dfs1(dfs1, 1);
  dfs2(dfs2, 1, 1);
  std::vector<int> p(n + 1);
  std::set<int> s;
  auto check = [&](int x) {
    if (x >= n || x < 1) return;
    if (isAncestor(pa[p[x + 1]], p[x])) {
      s.erase(x);
    } else {
      s.insert(x);
    }
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }
  for (int i = 1; i < n; i++) {
    check(i);
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    std::swap(p[x], p[y]);
    check(x);
    check(x - 1);
    check(y);
    check(y - 1);
    std::cout << (s.empty() ? "YES" : "NO") << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}