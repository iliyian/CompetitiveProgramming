// date: 2025-04-29 19:57:15
// tag: 安慰题的简单题

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> vec = {-1};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    vec.push_back(a[i] >> 2);
  }
  std::sort(vec.begin() + 1, vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  auto id = [&](int x) {
    return std::lower_bound(vec.begin() + 1, vec.end(), x) - vec.begin();
  };
  int len = vec.size() - 1;
  std::vector<std::vector<int>> g(len + 1), h(len + 1);
  for (int i = 1; i <= n; i++) {
    g[id(a[i] >> 2)].push_back(i);
    h[id(a[i] >> 2)].push_back(i);
  }
  for (int i = 1; i <= len; i++) {
    std::sort(g[i].begin(), g[i].end(), [&](const int &x, const int &y) {
      return a[x] < a[y];
    });
  }
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= len; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      ans[h[i][j]] = a[g[i][j]];
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
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