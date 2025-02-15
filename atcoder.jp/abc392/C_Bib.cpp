#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1), ans(n + 1), q(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> q[i];
  }
  for (int i = 1; i <= n; i++) {
    ans[q[i]] = q[p[i]];
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
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