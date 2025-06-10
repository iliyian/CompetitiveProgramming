#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> ans(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 1; j < i; j++) {
      if (a[j] > a[i]) {
        ans[j][a[i]] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << ans[i][j] << ' ';
    }
    std::cout << '\n';
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