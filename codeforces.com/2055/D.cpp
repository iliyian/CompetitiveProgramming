// date: 2025-01-20 12:57:16
// tag: 分类讨论

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, l;
  std::cin >> n >> k >> l;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  // if (n == 1) {
  //   std::cout << (a[1] + l - k) * 2 << '\n';
  //   return;
  // }
  a.push_back(l);
  n++;
  std::vector<double> b(n + 1);
  b[1] = 0;
  int T = a[1] * 2;
  double d = 0;
  for (int i = 2; i <= n; i++) {
    if (b[i - 1] + k <= a[i] - T / 2.0) { // 双向奔赴
      b[i] = (a[i] - T / 2.0 + b[i - 1] + k) / 2.0;
      T += a[i] - T / 2.0 - b[i - 1] - k;
    } else if (a[i] - T / 2.0 < b[i - 1] + k && b[i - 1] + k <= a[i] + T / 2.0) {
      b[i] = b[i - 1] + k; // 尽可能刚好
    } else {
      b[i] = a[i] + T / 2.0;
    }
    b[i] = std::min<double>(b[i], l);
    d += std::min<double>(b[i] - b[i - 1], k);
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << b[i] << " \n"[i == n];
  // }
  std::cout << (int)((a[1] + l - d) * 2) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}