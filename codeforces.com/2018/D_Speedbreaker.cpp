// date: 2025-02-16 15:46:08
// tag: 必要条件充作充分条件

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 2);
  std::vector<std::vector<int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int l = std::max(1ll, i - a[i] + 1), r = std::min(i + a[i] - 1, n);
    v[a[i]].push_back(i);
    b[l]++, b[r + 1]--;
  }
  int ans = 0, L = n + 1, R = 0;
  for (int i = 1; i <= n; i++) {
    for (auto j : v[i]) {
      L = std::min(L, j);
      R = std::max(R, j);
      if (R - L >= i) {
        std::cout << 0 << '\n';
        return;
      }
    }
    b[i] += b[i - 1];
    ans += b[i] == n;
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