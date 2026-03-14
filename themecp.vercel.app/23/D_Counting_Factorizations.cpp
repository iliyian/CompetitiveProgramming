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
 * @Author  : iliyian
 * @File    : D_Counting_Factorizations.cpp
 * @Time    : 2026-03-09 12:33:31
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<int> vis, primes;
constexpr int mod = 998244353;

void sieve(int N) {
  vis.assign(N + 1, 0);
  vis[1] = 1;
  for (int i = 2; i * i <= N; i++) {
    if (!vis[i]) {
      primes.push_back(i);
    }
    for (int p : primes) {
      if (i * p > N) break;
      vis[i * p] = 1;
      if (i % p == 0) break;
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> mp;
  std::vector<int> fac(n + 1), invfac(n + 1), inv(n + 1);
  fac[0] = fac[1] = invfac[0] = invfac[1] = inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }
  for (int i = 1; i <= n * 2; i++) {
    int x;
    std::cin >> x;
    mp[x]++;
  }
  int m = mp.size();
  std::vector<std::vector<int>> f(m + 1, std::vector<int>(std::max(n, m) + 1));
  f[0][0] = 1;
  int tot = 1, cnt = 0;
  for (auto [k, v] : mp) {
    for (int j = 0; j <= std::max(n, m); j++) {
      f[tot][j] += f[tot - 1][j] * invfac[v] % mod;
      f[tot][j] %= mod;
      if (!vis[k] && j >= 1) {
        f[tot][j] += f[tot - 1][j - 1] * invfac[v - 1] % mod;
        f[tot][j] %= mod;
      }
    }
    ++tot;
  }
  std::cout << fac[n] * f[tot - 1][n] % mod << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve(1000000);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
