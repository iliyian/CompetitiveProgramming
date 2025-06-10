// date: 2025-03-18 21:47:18
// tag: 比较神奇的基于 bool(偏序) 和基于二分的第k大最小（vice versas）的问题
// 这种第 k 大似乎确实很可以二分，这种把偏序转换成0/1权值的似乎也很常见

#include <bits/stdc++.h>
#define int long long

constexpr int N = 400;
int f[N + 1][N + 1][N + 1];

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<std::array<int, 3>> e = {{-1, -1, -1}};
  // memset(f, 0x3f, sizeof(f));
  // std::vector<std::vector<std::vector<int>>> f(n + 1,
  // std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1, LLONG_MAX /
  // 3)));
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 0; k <= m; k++) f[i][j][k] = LLONG_MAX / 3;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
    e.push_back({w, x, y});
    f[x][y][0] = f[y][x][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    f[i][i][0] = 0;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j][0] = std::min(f[i][j][0], f[i][k][0] + f[k][j][0]);
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     std::cerr << f[i][j][0] << ' ';
  //   }
  //   std::cerr << '\n';
  // }
  std::sort(e.begin() + 1, e.end());
  int k = 1;
  std::vector<int> rev(m + 1);
  for (int i = 1; i <= m; i++) {
    auto [w, x, y] = e[i];
    rev[k] = w;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j][k] = std::min({f[i][j][k - 1], f[i][x][k - 1] + f[y][j][k - 1],
                               f[x][j][k - 1] + f[i][y][k - 1]});
      }
    }
    // std::cerr << k << ": \n";
    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= n; j++) {
    //     std::cerr << f[i][j][k] << ' ';
    //   }
    //   std::cerr << '\n';
    // }
    k++;
  }
  while (q--) {
    int x, y, k;
    std::cin >> x >> y >> k;
    int l = 0, r = m, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (f[x][y][mid] < k)
        r = mid - 1, ans = rev[mid];
      else
        l = mid + 1;
    }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
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