#include <bits/stdc++.h>
#define int long long

constexpr int N = 5e5;
constexpr int mod = 998244353;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<int> fac(N + 1);
  fac[0] = 1;
  for (int i = 1; i <= N; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  std::vector<int> v(N + 1);
  std::vector<int> vv(N + 1);
    for (int i = 1; i <= N; i++) {
      v[i] = v[i - 1] * i % mod + fac[i - 1];
      v[i] %= mod;
  }
  for (int i = 1; i <= N; i++) {
    vv[i] = (vv[i - 1] * i % mod + 2 * v[i - 1] % mod) % mod + fac[i - 1];
    vv[i] %= mod;
  }
  std::vector<int> vvv(N + 1);
  for (int i = 1; i <= N; i++) {
    vvv[i] = ((vvv[i - 1] * i % mod + fac[i - 1]) % mod + 3 * vv[i - 1] % mod) % mod + 3 * v[i - 1] % mod;
    vvv[i] %= mod;
  }

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::cout << vvv[n] << '\n';
  }

  return 0;
}