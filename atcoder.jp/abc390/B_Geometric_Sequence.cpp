// date: 2025-02-12 12:55:18
// tag: 这玩意为什么有除法精度问题？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    if (a[i] * a[1] != a[2] * a[i - 1]) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
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