#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> nodes(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    nodes[x].push_back(i);
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> siz(n + 1), dfn(n + 1);
  int tot = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    dfn[u] = ++tot;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  dfs(dfs, 1, 0);
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) -> void {if (!x) return; for (int i = x; i <= n; i += i & -i) d[i] += c;};
  auto query = [&](int x) -> int {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;};
  int cnt = 0;
  for (int i = n; i >= 1; i--) {
    for (int j : nodes[i]) {
      if (query(dfn[j] + siz[j] - 1) - query(dfn[j] - 1) != cnt) {
        std::cout << j << '\n';
        return;
      }
    }
    for (int j : nodes[i]) {
      add(dfn[j], 1);
      cnt++;
    }
  }
  std::cout << 0 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}