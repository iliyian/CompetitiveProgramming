#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> f(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cout << "? " << i << ' ' << n << ' ';
    for (int j = 1; j <= n; j++) {
      std::cout << j << ' ';
    }
    std::cout << std::endl;
    std::cin >> f[i];
    g[f[i]].push_back(i);
  }
  int u = std::ranges::max_element(f) - f.begin();
  std::vector<int> ans;
  while (1) {
    ans.push_back(u);
    if (f[u] == 1) break;
    for (int v : g[f[u] - 1]) {
      std::cout << "? " << u << ' ' << 2 << ' ' << u << ' ' << v << ' ' << std::endl;
      int ans;
      std::cin >> ans;
      if (ans == 2) {
        u = v;
        break;
      }
    }
  }
  std::cout << "! " << ans.size() << ' ';
  for (int i : ans) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
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