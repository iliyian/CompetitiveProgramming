#include <bits/stdc++.h>
#define int long long

int x, y, p, q;

int ans[101][101][2], vis[101][101][2];

void solve() {
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      ans[i][j][0] = ans[i][j][1] = -1;
      vis[i][j][0] = vis[i][j][1] = false;
    }
  }
  std::cin >> x >> y >> p >> q;
  std::queue<std::array<int, 4>> que;
  que.push({x, y, 1, 0});
  vis[x][y][1] = 1;
  while (!que.empty()) {
    auto [a, b, c, t] = que.front(); que.pop();
    // if (vis[a][b][c]) continue;
    if (!a && !c) {
      std::cout << t << '\n';
      return;
    }
    if (c == 1) {
      for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b && j + i <= p; j++) {
          if (b - j > a - i + q && a - i > 0 && b - j > 0) {
            continue;
          }
          if (vis[a - i][b - j][0]) continue;
          vis[a - i][b - j][0] = 1;
          que.push({a - i, b - j, 0, t + 1});
        }
      }
    } else {
      for (int i = 0; i <= x - a; i++) {
        for (int j = 0; j <= y - b && j + i <= p; j++) {
          if (y - b - j > x - a - i + q && x - a - i > 0 && y - b - j > 0) {
            continue;
          }
          if (vis[a + i][b + j][1]) continue;
          vis[a + i][b + j][1] = 1;
          que.push({a + i, b + j, 1, t + 1});
        }
      }
    }
  }
  std::cout << -1 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}