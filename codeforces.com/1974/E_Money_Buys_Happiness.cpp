// date: 2025-04-04 17:53:30
// tag: 比较经典的基于w和v中较小的一个为索引进行dp的背包

#include <bits/stdc++.h>
#define int long long

void solve() {
  int m, x;
  std::cin >> m >> x;
  std::vector<int> c(m + 1), h(m + 1);
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    std::cin >> c[i] >> h[i];
    sum += h[i];
  }
  std::vector<int> f(sum + 1, -1);
  f[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = sum; j >= 0; j--) {
      if (j >= h[i] && f[j - h[i]] >= c[i]) {
        f[j] = std::max(f[j], f[j - h[i]] - c[i]);
      }
      if (f[j] != -1) {
        f[j] += x;
      }
    }
  }
  for (int i = sum; i >= 0; i--) {
    if (f[i] >= 0) {
      std::cout << i << '\n';
      return;
    }
  }
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