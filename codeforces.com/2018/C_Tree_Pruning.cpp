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
  std::vector<int> dep(n + 1), maxdep(n + 1), cnt(n + 2);
  auto dfs = [&](auto self, int u, int p) -> void {
    maxdep[u] = dep[u] = dep[p] + 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        maxdep[u] = std::max(maxdep[u], maxdep[v]);
      }
    }
    cnt[dep[u]]++, cnt[maxdep[u] + 1]--;
  };
  dfs(dfs, 1, 0);
  for (int i = 1; i <= n; i++) {
    // std::cerr << dep[i] << ' ' << maxdep[i] << '\n';
    cnt[i] += cnt[i - 1];
    // std::cerr << "cnt[i]: " << cnt[i] << '\n';
  }
  std::cout << n - *std::max_element(cnt.begin() + 1, cnt.end()) << '\n';
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