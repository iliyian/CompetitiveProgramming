// date: 2024-09-10 13:24:01
// tag: 图论，环，线性基，子集异或最值

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("main.in", "r", stdin);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<int> vis(n + 1), val(n + 1);  
  std::vector<int> d(63);
  auto insert = [&](int x) {
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return;
        }
      }
    }
  };

  auto dfs = [&](auto self, int u, int x) -> void {
    val[u] = x;
    vis[u] = true;
    for (auto &[v, w] : g[u]) {
      if (vis[v]) {
        insert(x ^ w ^ val[v]);
      } else {
        self(self, v, x ^ w);
      }
    }
  };
  dfs(dfs, 1, 0);
  
  int x = val[n];
  for (int i = 62; i >= 0; i--) {
    if ((d[i] ^ x) > x) {
      x ^= d[i];
    }
  }
  std::cout << x << "\n";

  return 0;
}