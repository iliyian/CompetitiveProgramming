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
 * @File    : G_Wafu.cpp
 * @Time    : 2025-12-06 20:27:34
 * @Comment : 怎么说呢？主要还是不敢定量的去深入研究导致的，感觉总体来说还是比较显然的......?顺便这题根本一点也不dp
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), p(61), sp(61);
  p[0] = 1;
  sp[0] = 1;
  for (int i = 1; i <= 60; i++) {
    p[i] = sp[i - 1] * i % mod;
    sp[i] = sp[i - 1] * p[i] % mod;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int ans = 1, idx = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= 60 && k >= (1ll << (a[i] - 1))) {
      k -= 1ll << (a[i] - 1);
      ans = ans * p[a[i]] % mod;
    } else {
      idx = a[i];
      break;
    }
  }
  std::cout << ans * [&](this auto &&self, int k, int idx) -> int {
    if (idx == 1 || k == 0) return 1;
    if (k == 1) return idx;
    int t = 63 - __builtin_clzll(k);
    return idx * sp[t] % mod * self(k - (1 << t), t + 1) % mod;
  } (k, idx) % mod << '\n';
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
