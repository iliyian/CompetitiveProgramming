#include <bits/stdc++.h>
#define int long long

int dx[] = {1, 0}, dy[] = {0, 1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  std::queue<std::pair<int, int>> q;
  q.push({1, 1});
  std::vector<std::vector<int>> prv(n + 1, std::vector<int>(m + 1, -1));
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 0; i < 2; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == '.') {
        if (prv[xx][yy] == -1) {
          prv[xx][yy] = i;
          q.push({xx, yy});
        }
      }
    }
  }
  auto print = [&](auto self, int x, int y) -> void {
    if (x >= 1 && y >= 1) {
      int z = prv[x][y];
      // std::cerr << x << ' ' << y << ' ' << prv[x][y] << '\n';
      if (z == 0) {
        self(self, x - 1, y);
        std::cout << 'S';
      } else if (z == 1) {
        self(self, x, y - 1);
        std::cout << 'D';
      }
    }
  };
  print(print, n, m);
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