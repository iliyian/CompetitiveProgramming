#include <bits/stdc++.h>
#define int long long

constexpr int N = 5000;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::bitset<N + 1>> f(n), rf(n);
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      char ch;
      std::cin >> ch;
      if (ch == '1') {
        f[i][j] = 1;
        adj[i].push_back(j);
      } else {
        f[j][i] = 1;
        adj[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    rf[i] = ~f[i];
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    if (f[x][y]) {
      std::cout << 0 << '\n';
      continue;
    }
    if ((f[x] & rf[y]).any()) {
      std::cout << 1 << '\n';
      continue;
    }
    bool f = false;
    std::queue<std::array<int, 2>> q;
    std::vector<int> vis(n);
    vis[x] = 1;
    q.push({0, x});
    while (!q.empty()) {
      auto [d, u] = q.front(); q.pop();
      if (u == y) {
        f = true;
        std::cout << d - 1 << '\n';
        break;
      }
      for (int v : adj[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          q.push({d + 1, v});
        }
      }
    }
    if (!f) {
      std::cout << -1 << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}