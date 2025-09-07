// date: 2025-07-19 12:15:17
// tag: 算是难得写了次prim算法。还好板子挺好用

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector<std::pair<int, int>> v;
  v.push_back({1, 1});
  for (int i = 1; i <= n; i++) {
    for (int j = 1 + (i == 1); j <= m; j++) {
      bool f = true;
      for (int d = 0; d < 4; d++) {
        int ii = i + dx[d], jj = j + dy[d];
        if (a[ii][jj] > a[i][j]) {
          f = false;
          break;
        }
      }
      if (f) {
        v.push_back({i, j});
      }
    }
  }
  std::priority_queue<std::array<int, 4>, std::vector<std::array<int, 4>>,
                      std::greater<>>
      q;
  auto id = [&](int x, int y) { return x * m + y; };
  auto nxt = [&](int x, int y) {
    return std::abs(x - y) == 1 || std::abs(x - y) == m;
  };
  int ans = 0, cnt = 0;
  std::vector<int> vis(v.size()), dis(v.size(), LLONG_MAX / 3);
  for (int _ = 0; _ < v.size(); _++) {
    int t = -1;
    for (int i = 0; i < v.size(); i++) {
      auto [x, y] = v[i];
      if (!vis[i] && (t == -1 || dis[i] < dis[t])) {
        t = i;
      }
    }
    vis[t] = 1;
    if (_) {
      ans += dis[t];
    }
    // std::cerr << v[t].first << ' ' << v[t].second << '\n';
    for (int i = 0; i < v.size(); i++) {
      auto [x, y] = v[i];
      auto [xx, yy] = v[t];
      dis[i] = std::min(dis[i],
        114 * std::abs(x - xx) + 5141 * std::abs(y - yy) +
              919810 * std::abs(a[x][y] - a[xx][yy]) + (1ll << 34));
    }
  }
  std::cout << ans << '\n';
  // std::cerr << cnt << '\n';
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