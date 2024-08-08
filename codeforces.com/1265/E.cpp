// date: 2024-08-04 17:33:05
// tag: 期望dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int x) {
  return qpow(x, mod - 2);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }

  int y = (100 - p[n]) * inv(100) % mod, z = 1; // x的系数与常数
  for (int i = n - 1; i >= 1; i--) {
    y = y * p[i] % mod * inv(100) % mod + (100 - p[i]) * inv(100) % mod;
    y %= mod;
  }
  for (int i = n - 1; i >= 1; i--) {
    z = z * p[i] % mod * inv(100) % mod + 1;
    z %= mod;
  }
  int x = ((1 - y) % mod + mod) % mod;
  int ans = z * inv(x) % mod;
  std::cout << ans << '\n';

  return 0;
}