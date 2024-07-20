// date: 2024-07-19 12:13:42
// tag: 树，构造

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::map<std::pair<int, int>, int> m;
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    m[{x, y}] = m[{y, x}] = i - 1;
  }
  std::vector<int> siz(n + 1);
  std::vector<int> ans;
  bool f = false;
  auto dfs = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
    if (siz[u] == 3) {
      if (u == 1) return;
      siz[u] = 0;
      ans.push_back({m[{p, u}]});
    } else if (siz[u] > 3) {
      f = true;
    }
  };
  dfs(dfs, 1, 0);
  if (n % 3 || f) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << ans.size() << '\n';
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}