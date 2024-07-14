// date: 2024-07-11 19:28:54
// tag: 暴力

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m, sx, sy, tx, ty;
  std::string sd;
  std::cin >> n >> m >> sx >> sy >> tx >> ty >> sd;
  
  auto check = [&](int ax, int ay, int bx, int by, int cx, int cy) -> bool {
    return abs(ax - bx) == abs(ay - by) && abs(bx - cx) == abs(by - cy)
      && (ax <= bx && bx <= cx || ax >= bx && bx >= cx);
  };

  auto id = [&](int x, int y) {
    return x * (m - 1) + y;
  };

  std::set<std::tuple<int, int, int, int>> vis;

  auto dfs = [&](auto self, int x, int y, int dx, int dy) -> int {
    if (vis.count({x, y, dx, dy})) return -1;
    vis.insert({x, y, dx, dy});

    int tmx = std::max((n - x) / dx, (1 - x) / dx), tmy = std::max((m - y) / dy, (1 - y) / dy);
    int t = std::min(tmx, tmy);
    int nx = x + dx * t, ny = y + dy * t;
    if (check(x, y, tx, ty, nx, ny)) {
      return 0;
    }
    // bool f = false;
    // if (nx == x && ny == y) vis.erase(id(x, y)), f = true;
    int ans = self(self, nx, ny, t == tmx ? -dx : dx, t == tmy ? -dy : dy);
    if (ans == -1) {
      return ans;
    }
    return ans + 1;
  };
  std::cout << dfs(dfs, sx, sy, sd.front() == 'D' ? 1 : -1, sd.back() == 'R' ? 1 : -1) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}