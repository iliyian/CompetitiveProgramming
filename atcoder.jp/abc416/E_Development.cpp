#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, LLONG_MAX / 3));
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    dis[x][y] = dis[y][x] = std::min(dis[x][y], w);
  }
  for (int i = 0; i <= n; i++) {
    dis[i][i] = 0;
  }
  int k, t;
  std::cin >> k >> t;
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    dis[0][x] = t,
    dis[x][0] = 0;
  }
  for (int k = 0; k <= n; k++) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  int q, ans = 0;
  std::cin >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans += (dis[i][j] == LLONG_MAX / 3 ? 0 : dis[i][j]);
    }
  }
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, y, w;
      std::cin >> x >> y >> w;
      dis[x][y] = dis[y][x] = std::min(dis[x][y], w);
      ans = 0;
      for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
          // ans -= (dis[i][j] == LLONG_MAX / 3 ? 0 : dis[i][j]);
          dis[i][j] = std::min({dis[i][j], dis[i][x] + dis[y][j] + dis[x][y], dis[i][y] + dis[x][j] + dis[y][x]});
          if (i && j) {
            ans += (dis[i][j] == LLONG_MAX / 3 ? 0 : dis[i][j]);
          }
        }
      }
    } else if (op == 2) {
      int x;
      std::cin >> x;
      dis[0][x] = t;
      dis[x][0] = 0;
      ans = 0;
      for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
          // ans -= (dis[i][j] == LLONG_MAX / 3 ? 0 : dis[i][j]);
          dis[i][j] = std::min({dis[i][j], dis[i][x] + dis[0][j] + dis[x][0], dis[i][0] + dis[x][j] + dis[0][x]});
          if (i && j) {
            ans += (dis[i][j] == LLONG_MAX / 3 ? 0 : dis[i][j]);
          }
        }
      }
    } else {
      std::cout << ans << '\n';
    }
    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= n; j++) {
    //     std::cerr << dis[i][j] << " \n"[j == n];
    //   }
    // }
  }
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