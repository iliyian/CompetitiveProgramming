// date: 2024-09-13 20:40:15
// tag: 贪心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
  }
  int ans = 0;
  auto dfs = [&](auto self, int u, int k) -> int {
    std::priority_queue<int> q;
    ans += s[u] * k;
    if (g[u].empty()) return s[u];
    int t = k / g[u].size(), r = k % g[u].size();
    for (int v : g[u]) {
      int val = self(self, v, t);
      q.push(val);
    }
    while (r--) {
      ans += q.top();
      q.pop();
    }
    return q.top() + s[u];
  };
  dfs(dfs, 1, k);
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}