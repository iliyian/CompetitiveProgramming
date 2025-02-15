#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int u = n, d = 1, l = m, r = 1;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '.' + a[i];
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '#') {
        u = std::min(u, i);
        d = std::max(d, i);
        l = std::min(l, j);
        r = std::max(r, j);
      }
    }
  }
  for (int i = u; i <= d; i++) {
    for (int j = l; j <= r; j++) {
      if (a[i][j] == '.') {
        std::cout << "No\n";
        return;
      }
    }
  }
  std::cout << "Yes\n";
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