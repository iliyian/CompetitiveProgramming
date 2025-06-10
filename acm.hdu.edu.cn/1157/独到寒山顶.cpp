#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(m + 1, LLONG_MAX / 3));
  for (int i = 1; i <= n; i++) {
    int r;
    std::cin >> r;
    for (int j = 1; j <= r; j++) {
      int x;
      std::cin >> x;
      a[i][x] = 1;
    }
  }
  std::queue<std::array<int, 3>> q;
  for (int i = 1; i <= n; i++) {
    if (!a[i][1]) {
      q.push({i, 1, 1});
      dis[i][1] = 1;
    }
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  while (!q.empty()) {
    auto [x, y, d] = q.front(); q.pop();
    if (dis[x][y] != d) continue;
    for (int d = 0; d < 4; d++) {
      int xx = x + dx[d], yy = y + dy[d];
      if (in(xx, yy) && !a[xx][yy] && dis[xx][yy] > dis[x][y] + 1) {
        q.push({xx, yy, dis[xx][yy] = dis[x][y] + 1});
      }
    }
  }
  int ans = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    if (!a[i][m]) {
      ans = std::min(ans, dis[i][m]);
    }
  }
  std::cout << ans << '\n';
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