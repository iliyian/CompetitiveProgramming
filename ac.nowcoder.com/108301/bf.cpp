#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1}, dy[] = {0, 1, 0};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  auto can = [&](int x1, int y1, int x2, int y2) -> bool {
    std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
    std::queue<std::pair<int, int>> q;
    q.push({x1, y1});
    vis[x1][y1] = 1;
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (x == x2 && y == y2) return true;
      for (int i = 0; i < 3; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!in(xx, yy) || vis[xx][yy] || a[xx][yy] == '1') continue;
        vis[xx][yy] = 1;
        q.push({xx, yy});
      }
    }
    return false;
  };
  auto move = [&](int sx, int sy, int tx, int ty, std::set<std::pair<int, int>> &s) {
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
    q.push({sx, sy});
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (y == sy + 1 && can(x, y, tx, ty)) {
        s.insert({x, y});
        continue;
      }
      for (int i = 0; i < 3; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!in(xx, yy) || vis[xx][yy] || a[xx][yy] == '1') continue;
        vis[xx][yy] = 1;
        q.push({xx, yy});
      }
    }
  };
  std::queue<std::vector<std::pair<int, int>>> q;
  for (int x = 1; x <= n; x++) {
    for (int i = 1; i <= n; i++) {
      if (can(x, 1, i, k + 1)) {
        q.push({{x, 1}});
        break;
      }
    }
  }
  // q.push({{1, 1}});
  while (!q.empty()) {
    auto v = q.front(); q.pop();
    auto [x, y] = v.back();
    bool f = false;
    for (int i = 1; i <= n; i++) {
      if (can(x, y, i, m)) {
        f = true;
        break;
      }
    }
    if (!f) {
      std::cout << "Yes\n";
      return;
    }
    for (int i = 0; i < 3; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (in(xx, yy) && a[xx][yy] == '0') {
        bool f = true;
        for (int i = 0; i < v.size(); i++) {
          auto [_x, _y] = v[i];
          if (_x == xx && _y == yy) {
            f = false;
            break;
          }
        }
        if (f) {
          bool g = false;
          for (int i = 1; i <= n; i++) {
            if (can(xx, yy, i, y + k)) {
              g = true;
              break;
            }
          }
          if (g) {
            v.push_back({xx, yy});
            q.push(v);
            v.pop_back();
          }
        }
      }
    }
  }
  std::cout << "No\n";
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