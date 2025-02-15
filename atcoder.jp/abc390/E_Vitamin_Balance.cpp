// date: 2025-02-12 13:30:35
// tag: 变种01背包，二分，
// 在01背包上用lower_bound确定满足某个v的最小w，因为不能直接根据v来动态规划，v的范围太大

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<std::vector<int>> f(4, std::vector<int>(x + 1, LLONG_MIN / 3));
  std::vector<std::vector<std::pair<int, int>>> a(4);
  for (int i = 1; i <= n; i++) {
    int V, v, w;
    std::cin >> V >> v >> w;
    a[V].push_back({v, w});
  }
  for (int i = 1; i <= 3; i++) {
    f[i][0] = 0;
    for (auto [v, w] : a[i]) {
      for (int j = x; j >= w; j--) {
        f[i][j] = std::max(f[i][j], f[i][j - w] + v);
      }
    }
    for (int j = 1; j <= x; j++) {
      f[i][j] = std::max(f[i][j], f[i][j - 1]);
    }
    // for (int j = 0; j <= x; j++) {
    //   std::cerr << f[i][j] << " \n"[j == x];
    // }
  }
  auto check = [&](int mid) {
    int sum = 0;
    for (int i = 1; i <= 3; i++) {
      auto u = std::lower_bound(f[i].begin(), f[i].end(), mid) - f[i].begin();
      if (u == f[i].size()) {
        return false;
      }
      sum += u;
    }
    return sum <= x;
  };
  int l = 1, r = INT_MAX, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << '\n';
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