#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b[i] = a[i];
  }
  std::sort(b.begin() + 1, b.end());
  
  int ans = 0;
  for (int j = 1; j < n; j++) {
    int cur = 0;
    int mx = b[j + 1], mn = b[j];
    for (int i = 1; i < n; i++) {
      int ai = std::min(mx, std::max(mx - k, a[i]));
      int ai1 = std::min(mx, std::max(mx - k, a[i + 1]));
      cur += std::abs(ai1 - ai);
    }
    ans = std::max(ans, cur);
    cur = 0;
    for (int i = 1; i < n; i++) {
      int ai = std::max(mn, std::min(mn + k, a[i]));
      int ai1 = std::max(mn, std::min(mn + k, a[i + 1]));
      cur += std::abs(ai1 - ai);
    }
    ans = std::max(ans, cur);
  }
  std::cout << ans << '\n';
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
