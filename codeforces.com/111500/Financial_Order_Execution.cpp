#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s;
  int n;
  std::cin >> s >> n;
  n /= 100;
  double ans = 0;
  int a[241] {}, p[241] {}, pri[241] {};
  for (int i = 1; i <= 240; i++) {
    double x;
    std::cin >> x >> a[i];
    p[i] = i;
    pri[i] = x * 100;
    a[i] /= 100;
  }
  std::sort(p + 1, p + 241, [&](const int &x, const int &y) {
    return pri[x] < pri[y];
  });
  if (s == "SELL") {
    for (int i = 240; i >= 1; i--) {
      int amount = std::min(a[p[i]], n);
      if (!amount) continue;
      n -= amount;
      double val = amount * pri[p[i]];
      double tax = val * 0.03;
      if (tax < 500) {
        tax = 5;
      } else {
        tax = std::round(tax) / 100.0;
      }
      ans += val + tax;
    }
  } else {
    for (int i = 1; i <= 240; i++) {
      int amount = std::min(a[p[i]], n);
      if (!amount) continue;
      n -= amount;
      double val = amount * pri[p[i]];
      double tax = val * 0.03;
      if (tax < 500) {
        tax = 5;
      } else {
        tax = std::round(tax) / 100.0;
      }
      // std::cerr << val << ' ' << tax << '\n';
      ans -= val + tax;
    }
  }
  std::cout << std::fixed << std::setprecision(2) << ans << '\n';
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