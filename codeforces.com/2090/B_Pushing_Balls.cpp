#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  auto check = [&](int x, int y) {
    bool f = true;
    for (int i = 1; i <= x; i++) {
      if (a[i][y] == '0') {
        f = false;
        break;
      }
    }
    bool g = true;
    for (int i = 1; i <= y; i++) {
      if (a[x][i] == '0') {
        g = false;
        break;
      }
    }
    return f || g;
  };
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      if (a[i][j] == '1' && !check(i, j)) {
        std::cout << "NO\n";
        return;
      }
    }
  }
  std::cout << "YES\n";
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