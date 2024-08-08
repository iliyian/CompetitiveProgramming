// date: 2024-07-31 14:01:57
// tag: 

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int p;
    std::cin >> p;
    g[p].push_back(i);
  }
  auto dfs = [&](auto self, int u, int p) -> void {
    if (g[u].empty()) return;
    int mn = INT_MAX;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        mn = std::min(mn, a[v]);
      }
    }
    if (u == 1) {
      a[u] += mn;
      return;
    }
    if (a[u] <= mn) {
      int t = (a[u] + mn) / 2;
      a[u] = t;
    } else {
      a[u] = mn;
    }
  };
  dfs(dfs, 1, 0);
  std::cout << a[1] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}