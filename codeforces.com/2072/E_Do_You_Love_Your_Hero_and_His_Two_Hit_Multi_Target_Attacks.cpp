#include <bits/stdc++.h>
#define int long long

void solve() {
  int k;
  std::cin >> k;
  int x = 0, y = 0;
  std::vector<std::pair<int, int>> ans;
  // int tmp = 0;
  for (int i = 500; i >= 2; i--) {
    while (i * (i - 1) / 2 <= k && k) {
      for (int j = 0; j < i; j++) {
        ans.push_back({x, y + j});
      }
      x++, y += i;
      k -= i * (i - 1) / 2;
      // std::cerr << k << '\n';
    }
  }
  std::cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    std::cout << x << ' ' << y << '\n';
  }
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