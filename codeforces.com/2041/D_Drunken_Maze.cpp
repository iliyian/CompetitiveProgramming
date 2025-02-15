// date: 2025-01-25 12:48:40
// tag: 带限制的最短路，类似分层图之类的

#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  int sx, sy, tx, ty;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'S') {
        sx = i, sy = j;
      }
      if (a[i][j] == 'T') {
        tx = i, ty = j;
      }
    }
  }
  std::vector<std::vector<std::vector<int>>> dis(12, std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1, inf)));
  std::queue<std::array<int, 4>> q;
  q.push({0, -1, sx, sy});
  auto check = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#';
  };
  while (!q.empty()) {
    auto [d, s, x, y] = q.front(); q.pop();
    if (s != -1 && dis[s][x][y] != d) continue;
    if (x == tx && y == ty) {
      std::cout << d << '\n';
      return;
    }
    // std::cerr << std::format("dsxy({},{},{},{}):", d, s, x, y) << '\n';
    int pd = s / 3, ps = s % 3;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (!check(xx, yy)) continue;
      if (i == pd && ps == 2) continue; // 不可以走第四步
      int ss = (i == pd && s != -1 ? s + 1 : i * 3);
      assert(ss < 12);
      // if (xx == 2) {
      //   std::cerr << std::format("xxyysspd({},{},{},{}):", xx, yy, ss, pd) << '\n';
      // }
      if (dis[ss][xx][yy] > d + 1) {
        dis[ss][xx][yy] = d + 1;
        q.push({d + 1, ss, xx, yy});
      }
    }
  }
  std::cout << -1 << '\n';
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