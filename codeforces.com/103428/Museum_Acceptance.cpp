#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n + 1), g(n * 3 + 1);
  auto id = [&](int x, int y) {
    return (x - 1) * 3 + y;
  };
  std::vector<int> d(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> d[i];
    for (int j = 1; j <= d[i]; j++) {
      int x;
      std::cin >> x;
      e[i].push_back(x);
    }
  }
  auto get = [&](int x, int i) {
    return std::find(e[x].begin(), e[x].end(), i) - e[x].begin() + 1;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= d[i]; j++) {
      int x = e[i][(j == d[i] ? 1 : j + 1) - 1];
      g[id(i, j)].push_back(id(x, get(x, i)));
    }
  }
  // for (int i = 1; i <= n * 3; i++) {
  //   std::cout << (i - 1) / 3 + 1 << ' ' << (i - 1) % 3 + 1 << ": ";
  //   for (int j : g[i]) {
  //     std::cout << (j - 1) / 3 + 1 << ' ' << (j - 1) % 3 + 1 << ' ';
  //   }
  //   std::cout << '\n';
  // }
  std::set<std::pair<int, int>> s;
  std::set<int> ss, vis;
  std::vector<int> ans(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    if (ss.count(u)) return;
    ss.insert(u);
    int x = (u - 1) / 3 + 1;
    if (u == (x - 1) * 3 + d[x]) {
      vis.insert(x);
    }
    for (int v : g[u]) {
      if (v != p) {
        int ux = (u - 1) / 3 + 1, vx = (v - 1) / 3 + 1;
        s.insert({std::min(ux, vx), std::max(ux, vx)});
        self(self, v, u);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!ans[i]) {
      s.clear();
      ss.clear();
      vis.clear();
      int x = (i - 1) * 3 + d[i];
      dfs(dfs, x, 0);
      for (int j : vis) {
        ans[j] = s.size();
      }
    }
    std::cout << ans[i] << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}