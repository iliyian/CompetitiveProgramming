// date: 2025-05-16 16:44:00
// tag: 一开始以为是博弈，然后仔细一看发现分明是构造，再看看，好家伙，这tmd不是二进制优化可行性01背包吗

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
  int visc[3] {};
  std::vector<int> vis(n + 1);
  auto dfs = [&](auto self, int u, int p, int c) -> void {
    for (int v : g[u]) {
      if (!vis[v]) {
        vis[v] = c;
        visc[c]++;
        self(self, v, u, 3 - c);
      }
    }
  };
  dfs(dfs, 1, 0, 1);
  std::vector<int> s0, s1;
  int t = n;
  for (int i = 0; (1ll << i) <= t; i++) {
    t -= 1ll << i;
  }
  for (int i = 0; i < t; i++) {
    s1.push_back(n - i);
  }
  if (visc[1] > visc[2]) {
    std::swap(visc[1], visc[2]);
    for (int i = 1; i <= n; i++) {
      vis[i] = 3 - vis[i];
    }
  }
  for (int i = 0; (1ll << i) <= (n - t); i++) {
    for (int j = 0; j < (1ll << i); j++) {
      (visc[1] >> i & 1 ? s0 : s1).push_back((1ll << i) + j);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 1) {
      std::cout << s0.back() << ' ';
      s0.pop_back();
    } else {
      std::cout << s1.back() << ' ';
      s1.pop_back();
    }
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