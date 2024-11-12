#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  while (m--) {
    for (int i = 1; i <= n - 1; i++) {
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
      }
    }
    for (int i = n; i >= 2; i--) {
      if (a[i - 1] > a[i]) {
        std::swap(a[i - 1], a[i]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
}

signed main() {
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}