#include <bits/stdc++.h>
#define int long long

struct Frac {
  int p, q;
  int val() {
    return 1.0 * p / q;
  }
  bool operator < (const Frac &b) const {
    return p * b.q < q * b.p;
  }
  bool operator < (int x) const {
    return *this < Frac{x, 1};
  }
  bool operator <= (const Frac &b) const {
    return !(b < *this);
  }
  bool operator > (const Frac &b) const {
    return !(*this <= b);
  }
  bool operator <= (int b) const {
    return !(Frac{b, 1} < *this);
  }
  Frac operator + (const Frac &b) const {
    int _q = q * b.q;
    int _p = p * b.q + q * b.p;
    int g = std::gcd(_p, _q);
    return Frac{_p / g, _q / g};
  }
  Frac operator + (int x) const {
    return *this + Frac{x, 1};
  }
};

Frac operator/(const Frac &a, int x) {
  Frac ans = a;
  ans.q *= x;
  int g = std::gcd(ans.p, ans.q);
  ans.p /= g;
  ans.q /= g;
  return ans;
}

Frac operator*(const Frac &a, int x) {
  Frac ans = a;
  ans.p *= x;
  int g = std::gcd(ans.p, ans.q);
  ans.p /= g;
  ans.q /= g;
  return ans;
}

Frac operator*(const Frac &a, const Frac &b) {
  int _p = a.p * b.p;
  int _q = a.q * b.q;
  int g = std::gcd(_p, _q);
  return Frac{_p / g, _q / g};
}

Frac operator/(const Frac &a, const Frac &b) {
  return a * Frac{b.q, b.p};
}

std::ostream& operator<<(std::ostream &os, const Frac &x) {
  std::cout << x.p << "/" << x.q;
  return os;
}

void solve() {
  int k, n, a, b, c, d;
  std::cin >> k >> n >> a >> b >> c >> d;
  // for (int i = 1; Frac{k, n * i} <= Frac{b, d}; i++) {
  //   auto x = Frac{k, n} / i;
  //   std::cout << "x=" << x << ", ans=" << x * i + x << '\n';
  //   // break;
  // }
  // for (double i = 1.0 * a / b; i <= 1.0 * c / d;
  //   //  i += ((1.0 * c / d) - (1.0 * a / b)) / 100
  //   i += 0.001
  //   ) {
  //   std::cout << "x=" << i << ", ans=" << i * (std::floor(k / (i * n)) + 1) << '\n';
  // }
  // std::cout << '\n';
  // return;
  auto calc = [&](Frac knx, const Frac &x) -> Frac {
    return x * knx + x;
  };
  int l = 1, r = 1e10;
  Frac knx;
  auto P = Frac{k, n}, R = Frac{c, d}, X = Frac{LLONG_MAX / 3, 1}, L = Frac{a, b};
  auto check = [&](const Frac &mid) -> bool {
    auto f = P / mid;
    if (f <= R) return true;
    return false;
  };
  while (l <= r) {
    int mid = (l + r) / 2;
    // std::cout << mid << ' ' << f << '\n';
    if (check(Frac{mid, 1})) r = mid - 1, knx = Frac{mid, 1}, X = P / mid;
    else l = mid + 1;
  }
  Frac maxval = calc(knx, X);
  if (X < L || X > R) {
    maxval = Frac{0, 1};
  }
  if (calc(Frac{(P / R).val(), 1}, R) > maxval) {
    X = R, knx = Frac{(P / R).val(), 1};
    maxval = calc(knx, X);
  }
  if (calc(Frac{(P / L).val(), 1}, L) > maxval) {
    X = L, knx = Frac{(P / L).val(), 1};
    maxval = calc(knx, X);
  }
  // std::cout << "knx=" << knx << ", X=" << X << '\n';;
  std::cout << calc(knx, X) << '\n';
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