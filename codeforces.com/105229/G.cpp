#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int ddx[] = {-2, -2, -1, 1, 2, 2, 1, -1}, ddy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

constexpr int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> b(m);
  std::vector<std::set<std::pair<int, int>>> pos(1 << m);
  for (int i = 0; i < m; i++) {
    std::cin >> b[i].first >> b[i].second;
  }
  for (int S = 0; S < (1 << m); S++) {
    for (int i = 0; i < m; i++) {
      if (S >> i & 1) {
        pos[S].insert({b[i].first, b[i].second});
      }
    }
  }
  // std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, -1));
  std::vector<std::vector<std::vector<int>>> f(1 << m, std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, -1)));
  auto check = [&](int x1, int y1, int x2, int y2, int S) -> bool {
    for (int i = 0; i < 4; i++) {
      int xx = x1 + dx[i], yy = y1 + dy[i];
      if (!pos[S].count({xx, yy})) {
        for (int j = 0; j < 2; j++) {
          int _xx = x1 + ddx[i * 2 + j], _yy = y1 + ddy[i * 2 + j];
          if (_xx == x2 && _yy == y2) {
            // std::cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << xx << ' ' << yy << ' ' << S << '\n';
            return true;
          }
        }
      }
    }
    return false;
  };
  auto dfs = [&](auto self, int x, int y, int S) -> int {
    // std::cerr << x << ' ' << y << ' ' << S << '\n';
    if (x < 0 || x > n || y < 0 || y > n) return 0;
    if (f[S][x][y] != -1) return f[S][x][y];
    for (int i = 0; i < m; i++) {
      if ((S >> i & 1) && check(b[i].first, b[i].second, x, y, S)) {
        return f[S][x][y] = 0;
      }
    }
    if (x == n && y == n) return 1;
    int lS = S, rS = S;
    for (int i = 0; i < m; i++) {
      if ((S >> i & 1)) {
        if (b[i].first == x && b[i].second == y + 1) {
          lS ^= 1 << i;
        }
        if (b[i].first == x + 1 && b[i].second == y) {
          rS ^= 1 << i;
        }
      }
    }
    return f[S][x][y] = (self(self, x, y + 1, lS) + self(self, x + 1, y, rS)) % mod;
  };
  std::cout << dfs(dfs, 0, 0, (1 << m) - 1) << '\n';
  // for (int S = 0; S < (1 << m); S++) {
  //   for (int i = 0; i <= n; i++) {
  //     for (int j = 0; j <= n; j++) {
  //       std::cerr << f[(1 << m) - 1][i][j] << " \n"[j == n];
  //     }
  //   }
  //   std::cerr << '\n';
  // }
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