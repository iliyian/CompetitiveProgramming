/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII               AAA               NNNNNNNN        NNNNNNNN
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I              A:::A              N:::::::N       N::::::N
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II            A:::::::A            N:::::::::N     N::::::N
  L:::::L                 I::::I  YYY:::::Y   Y:::::YYY  I::::I             A:::::::::A           N::::::::::N    N::::::N
  L:::::L                 I::::I     Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N   N::::::N
  L:::::L                 I::::I      Y:::::Y:::::Y      I::::I           A:::::A A:::::A         N:::::::N::::N  N::::::N
  L:::::L                 I::::I       Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N N::::::N
  L:::::L                 I::::I        Y:::::::Y        I::::I         A:::::A     A:::::A       N::::::N  N::::N:::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N    N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I      A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A             A:::::A   N::::::N      N::::::::N
L::::::::::::::::::::::LI::::::::I    YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N       N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A                 A:::::A N::::::N        N::::::N
LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII    YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN

 * 
 * ==============================================================================
 * @Author : iliyian
 * @File   : J.cpp
 * @Time   : 2025-10-22 17:37:47
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

std::vector<int> primes, minp, id;

void sieve(int N) {
  minp.assign(N + 1, 0);
  id.assign(N + 1, 0);
  int tot = 0;
  for (int i = 2; i <= N; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
      id[i] = tot++;
    }
    for (int p : primes) {
      if (i * p > N) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<std::vector<std::pair<int, int>>> v(3001);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    int S = 0, x = a[i];
    for (int j = 0; j < 16; j++) {
      if (x % primes[j] == 0) {
        while (x % primes[j] == 0) x /= primes[j];
        S |= 1 << j;
      }
    }
    if (x > 1) v[x].push_back({a[i], S});
    else v[0].push_back({a[i], S});
  }
  std::vector<int> f(1 << 16), g(1 << 16);
  f[0] = 1;
  std::ranges::copy(f, g.begin());
  for (auto [val, S] : v[0]) {
    // auto g = f;
    for (int i = 0; i < (1 << 16); i++) {
      g[i | S] += f[i] * val % mod;
      g[i | S] %= mod;
    }
    // f = g;
    std::ranges::copy(g, f.begin());
  }
  for (int fac : primes) {
    if (v[fac].empty()) continue;
    std::vector<std::vector<int>> g(2, std::vector<int>(1 << 16));
    std::vector<std::vector<int>> h(2, std::vector<int>(1 << 16));
    g[0] = f;
    std::ranges::copy(g, h.begin());
    for (auto [val, S] : v[fac]) {
      // auto h = g;
      for (int i = 0; i < (1 << 16); i++) {
        h[1][i | S] += (val * (fac - 1) / fac) % mod * g[0][i] % mod;
        h[1][i | S] %= mod;
        h[1][i | S] += g[1][i] * val % mod;
        h[1][i | S] %= mod;
      }
      // g = h;
      std::ranges::copy(h, g.begin());
    }
    for (int i = 0; i < (1 << 16); i++) {
      f[i] += g[1][i] % mod;
      f[i] %= mod;
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << 16); i++) {
    int s = f[i];
    for (int j = 0; j < 16; j++) {
      if (i >> j & 1) {
        s *= (primes[j] - 1) * qpow(primes[j], mod - 2) % mod;
        s %= mod;
      }
    }
    ans += s;
    ans %= mod;
  }
  std::cout << ans << '\n';
}

std::mt19937_64 rd(std::random_device{}());

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve(3000);

  auto calc = [&](int x) {
    int ans = x;
    for (int y = x; y > 1;) {
      int p = minp[y];
      while (y % p == 0) y /= p;
      ans = ans * (p - 1) / p;
    }
    return ans;
  };
  // for (int i = 1; i <= 30; i++) {
  //   std::cerr << calc(i) << ' ';
  // }

  // for (int t = 0; t < 1; t++) { 
  //   for (int n = 5; n <= 5; n++) {
  //     std::vector<int> a(n);
  //     for (int i = 0; i < n; i++) {
  //       a[i] = rd() % 10 + 1;
  //     }
  //     a = {79, 1, 1, 1, 2};
  //     for (auto i : a) {
  //       std::cout << i << ' ';
  //     }
  //     std::cout << '\n';
  //     int ans = 0;
  //     for (int i = 0; i < (1ll << n); i++) {
  //       int val = 1;
  //       for (int j = 0; j < n; j++) {
  //         if (i >> j & 1) {
  //           val *= a[j];
  //         }
  //       }
  //       ans += calc(val);
  //     }
  //     std::cout << ans << '\n';
  //   }
  // }

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
