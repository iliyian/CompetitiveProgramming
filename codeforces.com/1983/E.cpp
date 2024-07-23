// date: 2024-07-23 16:11:01
// tag: 概率与期望

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int a) {
  return qpow(a, mod - 2);
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  int suma = 0, sumb = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (i <= k) {
      suma += a[i];
      suma %= mod;
    } else {
      sumb += a[i];
      sumb %= mod;
    }
  }
  suma = suma * inv(k) % mod;
  sumb = sumb * inv(n - k) % mod;
  int alice = (int32_t)std::ceil((n - k + 1) / 2.0) * k % mod * inv(n - k + 1) % mod * suma % mod
    + (int32_t)std::ceil((n - k) / 2.0) * sumb % mod;
  alice %= mod;
  int bob = (suma * k % mod + sumb * (n - k) % mod + mod - alice) % mod;
  std::cout << alice << ' ' << bob << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}