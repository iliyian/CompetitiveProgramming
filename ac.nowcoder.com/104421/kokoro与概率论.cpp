#include <bits/stdc++.h>
#define int long long

int Cx2(int n) {
  if (n < 2) return 0;
  return n * (n - 1) / 2;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<double> p(n + 1);
  double pab = 0, pa = 0;
  for (int i = 0; i <= n; i++) {
    std::cin >> p[i];
  }
  for (int i = 0; i <= n; i++) {
    double x = p[i] * Cx2(n - i);
    pa += x;
    if (i > 0) {
      pab += x;
    }
  }
  std::cout << std::fixed << std::setprecision(3) << pab / pa << '\n';
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