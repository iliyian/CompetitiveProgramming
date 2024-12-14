// date: 2024-12-13 22:56:18
// tag: 基于基于区间单个决策二分导致的全局贪心形成的dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1, INT_MAX));
  f[0][0] = 0;
  for (int i = 1; i <= m; i++) {
    std::copy(f[i - 1].begin(), f[i - 1].end(), f[i].begin());
    for (int j = 1; j <= n; j++) {
      int l = 0, r = j, p = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (a[j] - a[mid] <= b[i]) r = mid - 1, p = mid;
        else l = mid + 1;
      }
      f[i][j] = std::min(f[i][j], f[i][p] + m - i);
    }
  }
  std::cout << (f[m][n] == INT_MAX ? -1 : f[m][n]) << '\n';
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