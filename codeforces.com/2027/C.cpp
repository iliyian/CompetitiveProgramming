// date: 2024-12-06 15:06:19
// tag: dag上最长路

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<int> vec = {INT_MIN};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[i] = a[i] + i - 1;
    vec.push_back(b[i]);
    vec.push_back(b[i] + i - 1);
  }
  auto id = [&](int x) -> int {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  std::sort(vec.begin(), vec.end());
  int len = vec.size() - 1;
  std::vector<std::vector<int>> g(len + 1);
  for (int i = 2; i <= n; i++) {
    g[id(b[i])].push_back(id(b[i] + i - 1));
  }
  std::vector<int> f(len + 1, INT_MAX);
  auto dfs = [&](this auto &&self, int u, int p) -> int {
  // auto dfs = [&](this auto &&self, int u, int p) -> int {
    if (f[u] != INT_MAX) return f[u];
    int mx = 0;
    for (auto v : g[u]) {
      if (v != p) { // self loops only
        // self(self, v, u);
        mx = std::max(mx, vec[v] - vec[u] + self(v, u));
      }
    }
    return f[u] = mx;
  };
  if (vec[id(n)] != n) {
    std::cout << n << '\n';
    return;
  }
  std::cout << dfs(id(n), 0) + n << '\n';
  // std::cout << f[1] << '\n';
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