#include <bits/stdc++.h>
#define int long long

constexpr int M = 1e5;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> x(n), y(n);
  auto len = [&](int a, int b) -> long double {
    return sqrtl((y[b] - y[a]) * (y[b] - y[a]) + (x[b] - x[a]) * (x[b] - x[a]));
  };
  auto S = [&](int a, int b, int c) {
    long double C = len(a, b), B = len(a, c), A = len(b, c);
    long double p = (A + B + C) / 2;
    return sqrtl(p * (p - A) * (p - B) * (p - C));
  };
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  int b = 1, c = 1;
  long double s = 0;
  while (c <= k) {
    s += S(0, c, (c + 1) % n);
    c++;
    c %= n;
  }
  long double ans = s;
  int a = (c + 1) % n, ini = c;
  while (true) {
    while ((a + 1) % n != b) {
      long double l = S(a % n, b, c), r = S((a + 1) % n, b, c);
      if (l > r)
      s += r - l;
      ans = std::max(ans, s);
      a++;
    }
    long double l = S(a % n, b, (b + 1) % n), r = S(a % n, c, (c + 1) % n);
    s += r - l;
    c++;
    b++;
    c %= n;
    b %= n;
    ans = std::max(ans, s);
    if (c == ini) break;
  }
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
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