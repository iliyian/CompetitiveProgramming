#include <bits/stdc++.h>
#define int long long

std::vector<int> primes, minp;

void sieve(int n) {
  minp.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
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

void solve() {
  int n;
  std::cin >> n;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  const int N = 1 << 23;
  // sieve(N);

  for (int i = 1200; i <= N; i++) {
    bool f = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        f = false;
        break;
      }
    }
    if (!f) continue;
    int ans = 0;
    int k = (i + 118) / 119;
    std::cout << i << ": \n";
    for (int j = 1; j <= i - 1; j++) {
      // std::cout << (qpow(j, i - 2, i) + (1 << k)) << " * " << (j + (1 << k) * (1 << k)) << '\n';
      ans ^= (qpow(j, i - 2, i) + (1 << k)) * (j + (1 << k) * (1 << k));
      // std::cerr << ans << '\n';
    }
    std::cout << ans % 998244353 << '\n';
    break;
    // for (int j = 30; j >= 0; j--) {
    //   std::cout << (ans >> j & 1);
    // }
    // std::cout << ' ' << ans << '\n';
  }

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}