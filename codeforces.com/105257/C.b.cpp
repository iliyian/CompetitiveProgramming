#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int S = (1 << n) - 1; S >= 0; S--) {
    std::vector<int> vis(n);
    bool f = true;
    for (int i = 0; i < n; i++) {
      int c = (S >> i & 1) ? a[i] : i;
      if (vis[c]) {
        f = false;
        break;
      }
      vis[c] = 1;
    }
    ans = std::max<int>(ans, __builtin_popcountll(S));
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