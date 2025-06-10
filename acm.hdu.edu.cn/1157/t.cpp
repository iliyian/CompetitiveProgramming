#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int c = 1; c <= 50; c++) {
    std::queue<std::pair<int, int>> q;
    std::vector<int> dis1(n + 1), dis2(n + 1), 
    for (int i = 1; i <= n; i++) {
      if (a[i] == c) {
        q.push({})
      }
    }
  }
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