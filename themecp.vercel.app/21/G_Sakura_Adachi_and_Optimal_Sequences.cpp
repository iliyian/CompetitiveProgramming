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
 * @File    : G_Sakura_Adachi_and_Optimal_Sequences.cpp
 * @Time    : 2026-03-04 00:10:41
 * @Comment : 还是比较有趣的一题吧？
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e6 + 3;
const int N = 1e6 + 2;

std::vector<int> fac(N + 1), invfac(N + 1), inv(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &i : a) std::cin >> i;
  for (auto &i : b) std::cin >> i;
  int ans = LLONG_MAX / 3, ways = 0;
  for (int k = 0;; k++) {
    bool f = true;
    for (int i = 0; i < n; i++) {
      if ((a[i] << k) > b[i]) {
        f = false;
        break;
      }
    }
    if (!f) break;
    std::vector<std::vector<int>> v(k + 1);
    auto c = a;
    for (auto &i : c) {
      i <<= k;
    }
    int now = k, nowway = 1;
    for (int i = k; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        // (5 + 2) * 4 + 1 * 2 + 0 * 1
        int way = (b[j] - c[j]) >> i;
        if (way > 0) {
          now += way;
          v[i].push_back(way);
          c[j] = c[j] + (way << i);
        }
      }
    }
    for (int i = 0; i <= k; i++) {
      int s = 0;
      for (auto j : v[i]) nowway = nowway * invfac[j] % mod, s += j;
      if (s >= mod) {
        nowway = 0;
        break;
      }
      nowway = nowway * fac[s] % mod;
    }
    if (now < ans) {
      ans = now, ways = nowway;
    }
  }
  std::cout << ans << ' ' << ways << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  fac[1] = fac[0] = invfac[1] = invfac[0] = inv[1] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
