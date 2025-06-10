// date: 2025-03-24 19:54:18
// tag: 码量还是很小的dp，关键在于发现比较显然的一个充要条件，只要可以到后面，就稳赢了，吃观察的动态增点的dag上最短路的dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  std::vector<int> f(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    f[i] = i - 1;
  }
  f[0] = LLONG_MAX / 3;
  int mind = n - 1;
  for (int i = 1; i <= n - 1; i++) {
    if (mind < n - i) {
      std::cout << 0;
    } else {
      std::cout << 1;
    }
    f[i] = std::min(f[i], f[i - 1] + 1);
    for (int v : g[i]) {
      mind = std::min(mind, (n - v) + f[i] + 1);
      f[v] = std::min(f[v], f[i] + 1);
    }
    // std::cerr << mind << '\n';
  }
  std::cout << '\n';
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