#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::set<std::pair<int, int>> e;
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, LLONG_MAX / 3));
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    dis[x][y] = dis[y][x] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (dis[i][j] % 2 == 1 && dis[i][j] > 1) {
        e.insert({i, j});
      }
    }
  }
  if (e.size() % 2) {
    std::cout << "First" << std::endl;
    std::cout << e.begin()->first << ' ' << e.begin()->second << std::endl;
    e.erase(e.begin());
  } else {
    std::cout << "Second" << std::endl;
  }
  while (1) {
    int x, y;
    std::cin >> x >> y;
    if (x == -1 && y == -1) {
      break;
    }
    e.erase({x, y});
    std::cout << e.begin()->first << ' ' << e.begin()->second << std::endl;
    e.erase(e.begin());
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