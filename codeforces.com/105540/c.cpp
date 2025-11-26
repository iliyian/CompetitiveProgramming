#include <bits/stdc++.h>
#define int long long

std::ifstream din("d.in"), dout("d.out");

bool f = true;

void solve() {
  int n;
  din >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    din >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> pa(21, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1), dfn(n + 1), s(n + 1);
  int tot = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[0][u] = p;
    dep[u] = dep[p] + 1;
    dfn[u] = ++tot;
    for (int i = 1; i <= 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 20; i >= 0; i--) {
      if (dep[pa[i][x]] >= dep[y]) {
        x = pa[i][x];
      }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
      if (pa[i][x] != pa[i][y]) {
        x = pa[i][x], y = pa[i][y];
      }
    }
    return pa[0][x];
  };
  auto getpa = [&](int x, int d) {
    for (int i = 0; i <= 20; i++) {
      if (d >> i & 1) {
        x = pa[i][x];
      }
    }
    return x;
  };
  dfs(dfs, 1, 0);
  int anscnt;
  dout >> anscnt;
  if (anscnt == -1) {
    std::ofstream os("-1.in");
    os << n << '\n';
    for (int i = 2; i <= n; i++) {
      os << pa[0][i] << ' ' << i << '\n';
    }
    return;
  }
  for (int i = 1; i <= anscnt; i++) {
    int x, y;
    dout >> x >> y;
    while (x != y) {
      if (dep[x] < dep[y]) std::swap(x, y);
      s[x]++;
      x = pa[0][x];
    }
  }
  for (int i = 2; i <= n; i++) {
    if (s[i] != 1) {
      f = false;
      return;
    }
  }
  // std::cout << "ACCEPTED\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  din >> t;

  while (t--) {
    solve();
  }
  if (!f) {
    std::cout << "WRONG ANSWER\n";
  } else {
    std::cout << "ACCEPTED\n";
  }

  return 0;
}