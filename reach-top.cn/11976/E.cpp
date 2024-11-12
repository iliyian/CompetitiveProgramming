#include <bits/stdc++.h>
#define int long long

void solve() {
  double x;
  std::cin >> x;
  double ans = 1, fac = 1;
  int sig = 1;
  for (int i = 1;; i++) {
    fac *= i;
    double cur = sig * pow(x, i) / fac;
    if (std::abs(cur) < 1e-7) {
      break;
    }
    ans += cur;
    sig *= -1;
  }
  printf("x=%0.6f, sum=%0.6f", x, ans);
}

signed main() {
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}