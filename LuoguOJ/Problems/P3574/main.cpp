// date: 2024-08-14 11:11:06
// tag: 贪心优化树形dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> f(n + 1), siz(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    std::vector<std::pair<int, int>> vec;
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        vec.push_back({f[v], (siz[v] - 1) * 2});
        siz[u] += siz[v];
      }
    }
    std::sort(vec.begin(), vec.end(),
      [&](const auto &x, const auto &y) {
        return x.first - x.second > y.first - y.second;
      }
    );
    int sumd = 0;
    for (auto [x, y] : vec) {
      f[u] = std::max(f[u], sumd + x + 1); // 此子树内完成的最小时刻
      sumd += y + 2;
    }
    if (u != 1) {
      f[u] = std::max(f[u], a[u]);
    }
  };
  dfs(dfs, 1, 0);
  std::cout << std::max(f[1], (n - 1) * 2 + a[1]) << '\n';

  return 0;
}