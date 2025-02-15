// date: 2025-01-27 21:22:58
// tag: 贪心，模拟，任务调度

#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
  }
  std::vector<int> l(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> l[i];
    l[i] += l[i - 1];
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<int> lstpos(n + 2), sum(n + 2);
  lstpos[n + 1] = LLONG_MAX / 3;
  for (int i = n; i >= 1; i--) {
    lstpos[i] = std::min(lstpos[i + 1], a[i].first) - a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i].second;
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << lstpos[i] << ' ';
  // }
  // std::cerr << '\n';
  while (q--) {
    int t;
    std::cin >> t;
    auto p = std::lower_bound(lstpos.begin() + 1, lstpos.end(), t) - lstpos.begin() - 1;
    int h;
    if (a[p].first > t) {
      // std::cerr << "1:" << '\n';
      std::cerr << lstpos[p] - (p ? sum[p - 1] : 0) << '\n';
      h = lstpos[p] - (p ? sum[p - 1] : 0);
    } else {
      // std::cerr << "2:" << '\n';
      // std::cerr << t - sum[p] << '\n';
      h = t - sum[p];
    }
    std::cout << std::upper_bound(l.begin() + 1, l.end(), h) - l.begin() - 1 << ' ';
    // std::cerr << lstpos[p] << ' ' << sum[p] << ' ' << lstpos[p] - (p ? sum[p - 1] : 0) << '\n';
  }
  std::cout << '\n';
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