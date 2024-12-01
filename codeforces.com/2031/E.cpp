// date: 2024-12-01 22:49:33
// tag: 很有趣的树形构造dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> f(n + 1);
  auto dfs = [&](auto self, int u) -> void {
    if (g[u].empty()) return;
    if (g[u].size() == 1) {
      self(self, g[u].front());
      f[u] = f[g[u].front()] + 1;
      return;
    }
    std::priority_queue<int, std::vector<int>, std::greater<>> q;
    for (int v : g[u]) {
      self(self, v);
      q.push(f[v]);
    }
    while (q.size() > 2) {
      int x = q.top(); q.pop();
      int y = q.top(); q.pop();
      q.push(std::max(x, y) + 1);
    }
    int x = q.top(); q.pop();
    int y = q.top(); q.pop();
    f[u] = std::max(x, y) + 1;
  };
  dfs(dfs, 1);
  std::cout << f[1] << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}