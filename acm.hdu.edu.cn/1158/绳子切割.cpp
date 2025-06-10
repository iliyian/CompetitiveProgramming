#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> d(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    d[x]++, d[y]++;
  }
  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  std::vector<int> vis(n + 1);
  for (int u = n; u >= 1; u--) {
    bool f = true;
    for (int v : g[u]) {
      if (v && v < u && d[v] == 1) {
        f = false;
        break;
      }
    }
    if (!f) {
      std::cout << 0 << '\n';
      return;
    }
    d[u] = 0;
    for (int v : g[u]) {
      d[v]--;
    }
  }
  std::cout << 1 << '\n';
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