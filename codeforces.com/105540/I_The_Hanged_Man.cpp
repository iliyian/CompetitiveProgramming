// date: 2025-09-28 23:44:06
// tag: 为什么想不到换根呢？为什么想不到换根之后递归一下就很容易证明了呢......

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int rt = 1;
  while (rt <= n && g[rt].size() % 2 == 1) rt++;
  if (rt == n + 1) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<std::pair<int, int>> ans;
  auto dfs = [&](this auto &&self, int u, int p) -> int {
    std::vector<int> son;
    for (int v : g[u]) {
      if (v != p) {
        int x = self(v, u);
        son.push_back(x);
      }
    }
    if (son.size() % 2 == 0) {
      for (int i = 0; i < son.size(); i += 2) {
        ans.push_back({son[i], son[i + 1]});
      }
      return u;
    } else {
      for (int i = 1; i < son.size(); i += 2) {
        ans.push_back({son[i], son[i + 1]});
      }
      return son[0];
    }
  };
  dfs(rt, 0);
  std::cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    std::cout << x << ' ' << y << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.in", "r", stdin);
  // freopen("d.out", "w", stdout);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}