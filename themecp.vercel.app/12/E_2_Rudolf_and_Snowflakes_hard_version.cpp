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
 * @File    : E_2_Rudolf_and_Snowflakes_hard_version.cpp
 * @Time    : 2025-12-02 16:24:53
 * @Comment : 诶嘿嘿，数学题实现起来真轻松，这题也确实很优雅和很有意思~~~
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::set<int> s;

constexpr int lim = 1'000'000'000'000'000'000;

void solve() {
  int n;
  std::cin >> n;
  if (s.count(n)) {
    std::cout << "YES\n";
    return;
  }
  int l = 2, r = 1000000000, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid * mid + mid + 1 <= n) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  if (ans != -1 && ans * ans + ans + 1 == n) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int k = 2; k <= 1000000; k++) {
    __int128 ans = k * k + k + 1;
    while (ans <= lim) {
      s.insert(ans);
      ans = ans * k + 1;
    }
  }

  // for (int k = 2; k <= 10; k++) {
  //   int n = 10;
  //   std::vector<int> f(n + 1);
  //   f[0] = 0, f[1] = 1;
  //   for (int i = 2; i <= n; i++) {
  //     f[i] = f[i - 1] + (f[i - 1] - f[i - 2]) * k;
  //     std::cout << f[i] << ' ';
  //   }
  //   std::cout << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
