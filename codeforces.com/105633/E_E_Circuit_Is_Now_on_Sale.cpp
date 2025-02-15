#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  int px = 0, py = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '.' + a[i];
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'P') {
        px = i, py = j;
      }
    }
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  auto solve = [&](this auto &&self, int x, int y) -> int {
    // std::cerr << x << ' ' << y << '\n';
    char ch = a[x][y];
    a[x][y] = '.';
    if (isdigit(ch)) {
      return ch - '0';
    }
    int _a = -1, _b = -1;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (in(xx, yy) && a[xx][yy] != '.') {
        if (_a == -1) _a = self(xx, yy);
        else if (_b == -1) _b = self(xx, yy);
        else assert(false);
      }
    }
    if (ch == '#') return _a;
    if (ch == '+') return _a + _b;
    if (ch == '-') return std::abs(_a - _b);
    if (ch == '*') return _a * _b;
    if (ch == '/') return std::max(_a, _b) / std::min(_a, _b);
    if (ch == 'P') std::cout << _a << '\n';
    return 0;
  };
  solve(px, py);
  // std::cout << solve(px, py) << '\n';
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