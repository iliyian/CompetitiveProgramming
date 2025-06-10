#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  bool f = true;
  std::vector<std::vector<int>> g(n * 3 + 1);
  std::vector<int> in(n * 3 + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, col;
    std::cin >> x >> y >> col;
    int a = (y + 1) / 2;
    int b = n + (n - x + 1);
    int c = n * 2 + (x * 2 - 1 - y + 1 + 1) / 2;
    if (a != col && b != col && c != col) {
      f = false;
    }
    if (a != col) {
      g[a].push_back(col);
      in[col]++;
    }
    if (b != col) {
      g[b].push_back(col);
      in[col]++;
    }
    if (c != col) {
      g[c].push_back(col);
      in[col]++;
    }
  }
  if (!f) {
    std::cout << "No\n";
    return;
  }
  std::queue<int> q;
  for (int i = 1; i <= 3 * n; i++) {
    if (!in[i]) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (!--in[v]) {
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n * 3; i++) {
    if (in[i]) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
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