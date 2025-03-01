// date: 2025-02-26 22:27:35
// tag: 依然是极其常见的从必要条件入手，然后呼吸一般自然的引入最短路，有思路后这点破码量根本不需要手速，只担心自己的过拟合问题
// 无穷次是个很可以入手的限制

#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n, s1, s2;
  std::cin >> n >> s1 >> s2;
  int m1;
  std::cin >> m1;
  std::vector<std::set<int>> g1(n + 1), g2(n + 1);
  for (int i = 1; i <= m1; i++) {
    int x, y;
    std::cin >> x >> y;
    g1[x].insert(y);
    g1[y].insert(x);
  }
  int m2;
  std::cin >> m2;
  for (int i = 1; i <= m2; i++) {
    int x, y;
    std::cin >> x >> y;
    g2[x].insert(y);
    g2[y].insert(x);
  }
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, inf));
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  q.push({dis[s1][s2] = 0, s1, s2});
  while (!q.empty()) {
    auto [d, x, y] = q.top(); q.pop();
    if (dis[x][y] != d) continue;
    for (int _x : g1[x]) {
      for (int _y : g2[y]) {
        if (dis[_x][_y] > dis[x][y] + std::abs(_x - _y)) {
          dis[_x][_y] = dis[x][y] + std::abs(_x - _y);
          q.push({dis[_x][_y], _x, _y});
        }
      }
    }
  }
  int ans = inf;
  for (int x = 1; x <= n; x++) {
    int y = x;
    // for (int y = 1; y <= n; y++) {
      for (auto _x : g1[x]) {
        if (g2[y].count(_x)) {
          ans = std::min(ans, dis[x][y]);
          // std::cerr << x << ' ' << y << ' ' << dis[x][y] << '\n';
          break;
        }
      }
    // }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     std::cerr << (dis[i][j] == inf ? -1 : dis[i][j]) << " \n"[j == n];
  //   }
  // }
  // std::cerr << '\n';
  std::cout << (ans == inf ? -1 : ans) << '\n';
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