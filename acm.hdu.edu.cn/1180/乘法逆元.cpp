// date: 2025-08-15 17:38:42
// tag: 三个小问题：乘号写成加号，没取模，板子抄错

#include <bits/stdc++.h>
#define int long long

std::vector<int> primes, minp;

void sieve(int n) {
  minp.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (i * p > n) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

int qpow(int a, int b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}

int xor_n(int n) {
  int t = n & 3;
  if (t & 1) return t / 2u ^ 1;
  return t / 2u ^ n;
}

constexpr int mod = 998244353;

void solve() {
  int p;
  std::cin >> p;
  int k = (p + 118) / 119;
  if (p <= 3000
    // || p == 3583
  ) {
    // std::cerr << k << '\n';
    __int128 ans = 0;
    for (int i = 1; i <= p - 1; i++) {
      ans ^= __int128(qpow(i, p - 2, p) + (1ll << k)) * __int128(i + (1ll << k) * (1ll << k));
    }
    ans %= mod;
    std::cout << (int)ans << '\n';
    return;
  }
  int ans = qpow(2, 2 * k, mod) * (xor_n(p - 1) % mod) % mod + qpow(2, k, mod) * (xor_n(p - 1) % mod) % mod;
  ans %= mod;
  ans += (p - 1) % mod * ((p - 1) % mod) % mod + 1;
  ans %= mod;
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  sieve(4000);
  // for (int p : primes) {
  //   int ans = 0;
  //   for (int i = 1; i <= p - 1; i++) {
  //     ans ^= i * qpow(i, p - 2, p);
  //     // std::cout << i << "*" << qpow(i, p - 2, p) << ' ' << i * qpow(i, p - 2, p) << '\n';
  //     // ans %= mod;
  //   }
  //   // std::cout << p << ": " << ans << ' ' << ans / p << ' ' << ans % p << '\n';
  //   std::cout << p << ": " << ans << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}