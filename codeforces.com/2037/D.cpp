// date: 2024-11-29 17:51:32
// tag: 边界情况别搞错了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, L;
  std::cin >> n >> m >> L;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
  }
  std::vector<int> x(m + 1), v(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> x[i] >> v[i];
  }
  // 应该用一个pq的，可以向前面借
  int ans = 0, k = 1;
  for (int i = 1; i <= n; i++) {
    int nowl = std::upper_bound(x.begin() + 1, x.end(), r[i - 1]) - x.begin();
    int nowr =
        std::prev(std::lower_bound(x.begin() + 1, x.end(), l[i])) - x.begin();
    std::sort(v.begin() + nowl, v.begin() + nowr + 1);
    int j = nowr;
    while (j >= nowl && k <= r[i] - l[i] + 1) k += v[j--];
    if (k <= r[i] - l[i] + 1) {
      std::cout << -1 << '\n';
      return;
    }
    ans += nowr - j;
  }
  std::cout << ans << '\n';
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