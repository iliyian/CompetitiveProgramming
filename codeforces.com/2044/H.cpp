// date: 2024-12-16 23:42:03
// tag: 较为复杂的二位前缀和，手玩即可，手推式子

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1)), b(n + 1, std::vector<int>(n + 1));
  std::vector<std::vector<int>> s(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
      s[i][j] = b[i][j] = a[i][j];
      s[i][j] += s[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = a[i][j] * j + a[i][j - 1];
      b[i][j] = b[i][j] * i + b[i - 1][j];
      s[i][j] += s[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] += a[i - 1][j];
      b[i][j] += b[i][j - 1];
    }
  }
  int x1, y1, x2, y2;
  auto get = [&](std::vector<std::vector<int>> &a) {
    return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
  };
  while (q--) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    int m = y2 - y1 + 1;
    int ans = get(a);
    // std::cout << ans << '\n';
    ans -= (y1 - 1) * get(s);
    // std::cout << ans << '\n';
    ans += (get(b) - x1 * get(s)) * m;
    std::cout << ans << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}