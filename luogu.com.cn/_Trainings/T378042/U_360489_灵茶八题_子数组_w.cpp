#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int c0 = 1, c1 = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] >> i & 1) c1++, ans += c0 << i;
      else c0++, ans += c1 << i;
      if (a[j] >> i & 1) {
        std::swap(c0, c1);
      }
      
    }
    // std::cerr << ans << '\n';
  }
  std::cout << ans << '\n';
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