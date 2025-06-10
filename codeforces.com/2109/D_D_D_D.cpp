#include <bits/stdc++.h>
#define int long long


void solve() {
  int n, m, l;
  std::cin >> n >> m >> l;
  std::vector<int> a(l + 1);
  std::array<int, 2> mx = {0, -1};
  for (int i = 1; i <= l; i++) {
    std::cin >> a[i];
    if (a[i] % 2 == 0) {
      mx[0] += a[i];
      if (mx[1] != -1) {
        mx[1] += a[i];
      }
    } else {
      auto _mx = mx;
      if (mx[1] != -1) {
        _mx[0] = std::max(_mx[0], mx[1] + a[i]);
      }
      _mx[1] = std::max(_mx[1], mx[0] + a[i]);
      mx = _mx;
    }
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::array<int, 2>> dis(n + 1, {-1, -1});
  std::queue<std::array<int, 2>> q;
  dis[1][0] = 0;
  q.push({0, 1});
  // std::cerr << mx[0] << ' ' << mx[1] << '\n';
  while (!q.empty()) {
    auto [d, u] = q.front(); q.pop();
    for (int v : g[u]) {
      if (dis[v][d & 1 ^ 1] == -1) {
        dis[v][d & 1 ^ 1] = d + 1;
        q.push({d + 1, v});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    // std::cerr << dis[i][0] << ' ' << dis[i][1] << " \n"[i == n];
    if (dis[i][0] != -1 && mx[dis[i][0] & 1] >= dis[i][0]) {
      std::cout << 1;
    } else if (dis[i][1] != -1 && mx[dis[i][1] & 1] >= dis[i][1]) {
      std::cout << 1;
    } else {
      std::cout << 0;
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