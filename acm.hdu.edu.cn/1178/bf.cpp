#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    a[x][y] += w;
  }
  int ans = 0;
  for (int lx = 1; lx <= n; lx++) {
    for (int rx = lx; rx <= n; rx++) {
      for (int ly = 1; ly <= n; ly++) {
        for (int ry = ly; ry <= n; ry++) {
          int cur = 0;
          if ((rx - lx + 1) * (ry - ly + 1) <= k) {
            for (int i = lx; i <= rx; i++) {
              for (int j = ly; j <= ry; j++) {
                cur += a[i][j];
              }
            }
          }
          if (cur == 28) {
            std::cout << lx << ' ' << ly << ' ' << rx << ' ' << ry << '\n';
          }
          ans = std::max(ans, cur);
        }
      }
    }
  }
  std::cout << ans << '\n';
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