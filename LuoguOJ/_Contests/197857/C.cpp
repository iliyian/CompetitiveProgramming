#include <bits/stdc++.h>
#define int long long

signed main() {
  int n;
  double m;
  std::cin >> n >> m;
  m /= 100;
  int s = n * (n + 1) / 2;
  for (int i = 1; i <= n; i++) {
    if (double(i) / s >= m) {
      std::cout << i << '\n';
      return 0;
    }
  }
  std::cout << -1 << '\n';
  return 0;
}