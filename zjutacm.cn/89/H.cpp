#include <bits/stdc++.h>
#define int long long

int dx[] = {1, 0}, dy[] = {0, 1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  std::queue<std::array<int, 3>> q;
  std::vector<std::vector<std::vector<bool>>> vis(n + 1, std::vector<std::vector<bool>>(m + 1, std::vector<bool>(n * m * 3 + 10)));
  q.push({1, 1, a[1][1]});
  vis[1][1][a[1][1] + n * m] = 1;
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  while (!q.empty()) {
    auto val = q.front(); q.pop();
    int x = val[0], y = val[1], d = val[2];
    if (x == n && y == m) {
      if (d == 0) {
        std::cout << "YES\n";
        return;
      }
      continue;
    }
    for (int i = 0; i < 2; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (!in(xx, yy)) continue;
      int dd = d + a[xx][yy];
      if (!vis[xx][yy][dd + n * m]) {
        vis[xx][yy][dd + n * m] = 1;
        q.push({xx, yy, dd});
      }
    }
  }
  std::cout << "NO\n";
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