#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

std::pair<int, int> calc(int a, int b, int r1, int r2, int x) {
  return {(((x * a % mod * b % mod + b * r1 % mod) % mod + a * r2 % mod) % mod + r1 * r2 / x % mod) % mod, r1 * r2 % x};
}

std::pair<int, int> qpow(int a, int b, int x) {
  int tans = 0, rans = 1;
  int ta = a / x, ra = a % x;
  while (b) {
    if (b & 1) {
      // ans = ans * a % mod;
      auto [fi, sc] = calc(tans, ta, rans, ra, x);
      tans = fi, rans = sc;
    }
    // a = a * a % mod;
    auto [fi, sc] = calc(ta, ta, ra, ra, x);
    ta = fi, ra = sc;
    b >>= 1;
  }
  return {tans, rans};
}

void solve() {
  int n;
  std::cin >> n;
  int a = 1, b;
  std::vector<int> p(n + 1), e(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i] >> e[i];
  }
  std::cin >> b;
  for (int i = 1; i <= n; i++) {
    while (b % p[i] == 0 && e[i]) {
      b /= p[i], e[i]--;
    }
  }
  int tans = 0, rans = 1;
  for (int i = 1; i <= n; i++) {
    if (e[i]) {
      auto [fi, sc] = qpow(p[i], e[i], b);
      auto [fi2, sc2] = calc(tans, fi, rans, sc, b);
      tans = fi2, rans = sc2;
    }
  }
  std::cout << tans << '\n';
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