#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    int x = -1;
    for (int j = 1; j <= m; j++) {
      if (x != -1 && a[i][j] % n != x) {
        std::cout << -1 << '\n';
        return;
      }
      x = a[i][j] % n;
    }
    ans[x + 1] = i;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
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