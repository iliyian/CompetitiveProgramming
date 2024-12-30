#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> d0, d1, dep(n + 1);
  auto dfs = [&](auto self, int u) -> void {
    if (a[u] == 1) d1.push_back(dep[u]);
    if (a[u] == 0) d0.push_back(dep[u]);
    for (int v : g[u]) {
      dep[v] = dep[u] + 1;
      self(self, v);
    }
  };
  dfs(dfs, 1);
  auto white = [&]() {
    std::cout << "Fatalis Hikari\n";
  };
  auto black = [&]() {
    std::cout << "poor Hikari\n";
  };
  std::sort(d1.begin(), d1.end());
  std::sort(d0.begin(), d0.end());
  if (d1.size() > d0.size()) {
    black();
    return;
  }
  int dis0 = 0, dis1 = 0;
  for (int i = 0; i < d1.size(); i++) {
    dis0 += d0[i], dis1 += d1[i];
    if (dis1 < dis0) {
      black();
      return;
    }
  }
  white();
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}