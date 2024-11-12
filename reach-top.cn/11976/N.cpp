#include <bits/stdc++.h>
#include <cstdio>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int k;
  std::cin >> k;
  for (int i = n; i >= 1; i--) {
    if (a[i] == k) {
      std::cout << i << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
}

signed main() {
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}