#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int len = 1; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      std::vector<int> b = a;
      for (int i = l; i <= r; i++) {
        b[i] ^= 1;
      }
      if (std::count(b.begin() + 1, b.end(), 1) > n / 2) {
        std::cout << "Yes\n";
        return;
      }
    }
  }
  std::cout << "No\n";
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