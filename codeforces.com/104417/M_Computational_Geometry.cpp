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
  auto S = [&](int a, int b, int c) -> long double {
    // if (a == b || b == c || a == c) return 0.0l;
    // if (!(a != b && a != c && b != c)) {
    //   std::cout << "gg\n";
    // }
    long double C = len(a, b), B = len(a, c), A = len(b, c);
    long double p = (A + B + C) / 2;
    long double ans = sqrtl(p * (p - A) * (p - B) * (p - C));
    if (std::isnan(ans)) {
      return 0;
    }
    return ans;
  };
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  int b = 0, c = 1;
  long double s0 = 0;
  while (c < k) {
    s0 += S(0, c, (c + 1) % n);
    c++;
    c %= n;
  }
  int a = (c + 1) % n, ini = c;
  if (k == 1) s0 = 0;
  long double ans = (k == 1 ? 0 : s0) + S(a, b, c);
  while (true) {
    // std::cerr << a << ' ' << b << ' ' << c << ' ' << ans << '\n';
    while ((a + 1) % n != b) {
      long double l = S(a % n, b, c), r = S((a + 1) % n, b, c);
      if (l > r) break;
      a = (a + 1) % n;
    }
    ans = std::max(ans, (k == 1 ? 0 : s0) + S(a, b, c));
    long double l = S(c, b, (b + 1) % n), r = S((b + 1) % n, c, (c + 1) % n);
    s0 += r - l;
    c++;
    b++;
    c %= n;
    b %= n;
    if (c == a) a = (a + 1) % n;
    ans = std::max(ans, (k == 1 ? 0 : s0) + S(a, b, c));
    if (c == ini) break;
  }
  if (std::abs(ans - std::floor(ans)) <= 1e-6) {
    ans = std::floor(ans);
  } else if (std::abs(ans - 0.5 - std::floor(ans)) <= 1e-6) {
    ans = std::floor(ans) + 0.5;
  }
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
  // std::cerr << '\n';
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