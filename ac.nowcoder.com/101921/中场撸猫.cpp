#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
    std::sort(a[i].begin() + 1, a[i].end());
  }
  std::vector<std::vector<int>> ans(n + 1, {0});
  ans[1].push_back(1);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
      auto p = std::lower_bound(a[i].begin() + 1 + ans[i].back(), a[i].end(), a[i - 1][ans[i - 1][j]]) - a[i].begin();
      // std::cerr << i << ' ' << j << ' ' << p << '\n';
      if (p == n + 1) {
        break;
      }
      // std::cerr << "qwq\n";
      ans[i].push_back(p);
    }
    if (ans[i].size() != i || ans[i].back() == n) {
      std::cout << i - 1 << '\n';
      return;
    }
    ans[i].push_back(ans[i].back() + 1);
    // for (auto j : ans[i]) {
    //   std::cerr << j << ' ';
    // }
    // std::cerr << '\n';
  }
  std::cout << n << '\n';
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