// date: 2024-07-04 21:39:26
// tag: 树形dp，bfs

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), p(n + 1), dep(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = -a[i];
  }
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
    a[x] -= a[i];
  }
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    for (int v : g[u]) {
      self(self, v, u);
    }
  };
  for (int i = 1; i <= n; i++) {
    if (g[i].empty()) {
      a[i] = inf;
    }
  }
  dfs(dfs, 1, 0);

  int ans = 0;
  for (int i = n; i >= 1; i--) {
    std::queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : g[u]) {
        int delta = std::min(-a[i], a[v]);
        if (delta > 0) {
          a[i] += delta;
          a[v] -= delta;
          ans += delta * (dep[v] - dep[i]);
        }
        q.push(v);
      }
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}