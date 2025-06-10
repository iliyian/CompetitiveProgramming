#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m + 1), b(n + 2);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
    if (a[i] == n) a[i]--;
    b[std::max(n - a[i], 1ll)]++;
    b[n]--;
  }
  for (int i = 1; i <= n; i++) {
    b[i] += b[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    b[i] += b[i - 1];
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += b[a[i]];
    if (a[i] + a[i] >= n) {
      ans -= a[i] + a[i] - n + 1;
      // std::cerr << (a[i] + a[i] - n) / 2 + 1 << '\n';
    }
    // std::cerr << ans << '\n';
  }
  std::cout << ans << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << b[i] << ' ';
  // }
  // std::cerr << '\n';
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