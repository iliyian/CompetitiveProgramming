#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e3;

bool vis[N + 1][N + 1];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, n, m;

bool in(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

void solve() {
  std::cin >> n >> m;
  std::vector<std::vector<char>> a(n + 1, std::vector<char>(m + 1));
  std::vector f(n + 1, std::vector<std::vector<std::vector<bool>>>(m + 1, std::vector<std::vector<bool>>(n + 1, std::vector<bool>(m + 1))));
  std::vector vis(n + 1, std::vector<std::vector<std::vector<bool>>>(m + 1, std::vector<std::vector<bool>>(n + 1, std::vector<bool>(m + 1))));
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      tot += a[i][j] == '.';
    }
  }
  std::queue<std::array<int, 4>> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'O')  continue;
      for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
          if (a[x][y] == '.') continue;
          q.push({i, j, x, y});
        }
      }
    }
  }
  while (!q.empty()) {
    auto [i, j, x, y] = q.front(); q.pop();
    if (!in(i, j) || !in(x, y) || vis[i][j][x][y]) continue;
    vis[i][j][x][y] = true;
    f[i][j][x][y] = true;
    for (int d = 0; d < 4; d++) {
      q.push({i + dx[d], j + dy[d], x + dx[d], y + dy[d]});
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j])
      int cnt = 0;
      for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {

        }
      }
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}