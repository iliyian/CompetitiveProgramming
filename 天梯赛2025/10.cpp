#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  // std::array<std::vector<int>, 3> a;
  std::array<std::multiset<int>, 3> a;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    // a[y].push_back(x);
    a[y].insert(x);
  }
  // for (int i = 0; i < 3; i++) {
  //   std::sort(a[i].begin(), a[i].end());
  // }
  // for (int i = 0; i < a[1].size(); i++) {
  std::vector<std::array<std::pair<int, int>, 3>> ans;
  for (auto i : a[1]) {
    // int sum = a[1][i] * 2;
    int sum = i * 2;
    // for (int j = 0; j < a[0].size(); j++) {
    for (auto j : a[0]) {
      // auto p = std::lower_bound(a[2].begin(), a[2].end(), sum - a[0][j]);
      auto p = a[2].lower_bound(sum - j);
      if (p != a[2].end() && *p == sum - j) {
        ans.push_back({std::pair<int, int>{j, 0}, std::pair<int, int>{i, 1}, std::pair<int, int>{*p, 2}});
        a[2].erase(p);
      }
    }
  }
  std::sort(ans.begin(), ans.end(), [&](const auto &x, const auto &y) {
    return std::tie(x[1].first, x[0].first) < std::tie(y[1].first, y[0].first);
  });
  ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
  for (auto &x : ans) {
    for (int i = 0; i < 3; i++) {
      std::cout << "[" << x[i].first << ", " << x[i].second << "]";
      if (i == 2) {
        std::cout << '\n';
      } else {
        std::cout << ' ';
      }
    }
  }
  if (ans.empty()) {
    std::cout << -1;
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}