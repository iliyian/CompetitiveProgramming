// date: 2025-04-01 21:44:43
// tag: 总之是比较神奇的一道差分题，离散化之类的。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), b(n + 1), v = {-1};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    v.push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    v.push_back(b[i]);
  }
  auto id = [&](int x) {
    return std::lower_bound(v.begin(), v.end(), x) - v.begin();
  };
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  int len = v.size() - 1;
  std::vector<int> sa(len + 2), sb(len + 2);
  for (int i = 1; i <= n; i++) {
    sa[1]++, sa[id(b[i]) + 1]--;
    sb[id(a[i]) + 1]++, sb[id(b[i]) + 1]--;
  }
  int ans = 0;
  for (int i = 1; i <= len; i++) {
    sa[i] += sa[i - 1];
    sb[i] += sb[i - 1];
    if (sb[i] <= k) {
      ans = std::max(ans, v[i] * sa[i]);
      // ans = std::max(ans, v[i]);
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