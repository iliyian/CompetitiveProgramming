#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, l, r;
  std::cin >> n >> l >> r;
  std::vector<int> a(n + 1);
  std::vector<int> vl, vr;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (i <= r) vl.push_back(a[i]);
    if (i >= l) vr.push_back(a[i]);
  }
  std::sort(vl.begin(), vl.end());
  std::sort(vr.begin(), vr.end());
  int ans = LLONG_MAX;
  // std::cout << vl.size() << ' ' << vr.size() <<  '\n';
  if (vl.size() >= r - l + 1) {
    ans = std::min(ans, std::accumulate(vl.begin(), vl.begin() + r - l + 1, 0ll));
  }
  if (vr.size() >= r - l + 1) {
    ans = std::min<int>(ans, std::accumulate(vr.begin(), vr.begin() + r - l + 1, 0ll));
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