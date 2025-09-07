#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {
  if (!a | !b) return a + b;
  int az = __builtin_ctzll(a);
  int bz = __builtin_ctzll(b);
  int z = std::min(az, bz);
  a >>= az, b >>= bz;
  while (a != b) {
    int diff = b - a;
    az = __builtin_ctzll(diff);
    b = std::min(a, b), a = std::abs(diff) >> az;
  }
  return a << z;
}

void solve() {
  int n;
  std::cin >> n;
  int l = 1, r = n;
  int ansp = 0, ansq = 1;
  auto check = [&](int mid) {
    // __int128 p = __int128(1) * mid * mid - mid + 2 * n, q = __int128(2) * mid;
    int p = mid * mid - mid + 2 * n, q = 2 * mid;
    int g = gcd(p, q);
    // return std::pair{p, q};
    return std::pair{p / g, q / g};
  };
  auto cmp = [&](const auto &x, const auto &y) {
    return x.first * y.second < x.second * y.first;
  };
  while (l < r) {
    int mid = (l + r) / 2;
    if (cmp(check(mid), check(mid + 1))) r = mid;
    else l = mid + 1;
  }
  auto [p, q] = check(l);
  // int g = gcd(p, q);
  // std::cout << (int)p / g << ' ' << (int)q / g << '\n';
  std::cout << p << ' ' << q << '\n';
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