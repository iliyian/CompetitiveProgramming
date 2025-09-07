#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  k--;
  std::vector<std::vector<int>> a(n, std::vector<int>(m)), b(n, std::vector<int>(m));
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      std::cin >> c;
      a[i][j] = c == 'g';
      b[i][j] = c == '.';
      cnt += c == 'g';
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] += a[i - 1][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      a[i][j] += a[i][j - 1];
    }
  }
  int ans = 0;
  // std::cerr << ans << '\n';
  auto get = [&](int lx, int ly, int rx, int ry) {
    lx = std::max(lx, 0ll);
    ly = std::max(ly, 0ll);
    rx = std::min(rx, n - 1);
    ry = std::min(ry, m - 1);
    return a[rx][ry] - (lx ? a[lx - 1][ry] : 0) - (ly ? a[rx][ly - 1] : 0) + (lx && ly ? a[lx - 1][ly - 1] : 0);
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j]) {
        ans = std::max(ans, cnt - get(i - k, j - k, i + k, j + k));
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