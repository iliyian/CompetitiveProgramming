#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> d(n + 2), a(n + 2);
  d[n + 1] = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    std::cin >> d[i] >> a[i];
  }
  std::stack<std::pair<int, int>> s;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    s.push({d[i], a[i]});
    int ct = d[i], res = 0;
    while (!s.empty()) {
      auto [td, ta] = s.top(); s.pop();
      int t = std::min({ct + (res + ta) / m - 1, td + k - 1, d[i + 1] - 1});
      if (td + k - 1 < ct) continue; // 目前都未过期
      if (d[i + 1] - 1 == t) { // 未吃完
        ans += d[i + 1] - ct;
        ta = ta + res - (d[i + 1] - ct) * m;
        s.push({td, ta});
        break;
      }
      if (td + k - 1 == t) {
        res = 0;
      } else {
        res += ta - (t - ct + 1) * m;
      }
      ans += t - ct + 1;
      ct = t + 1;
    }
  }
  std::cout << ans << '\n';
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