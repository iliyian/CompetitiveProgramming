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
 * @File    : E_Mister_B_and_Angle_in_Polygon.cpp
 * @Time    : 2025-12-09 19:15:02
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

using std::numbers::pi;

void solve() {
  int n, a;
  std::cin >> n >> a;
  long double aa = a / 180.0l * pi;
  int ansi = 2, ansk = 3;
  long double ans = LLONG_MAX / 3;
  long double theta = pi * 2 / n;
  int j = 1;
  auto get = [&](int i, int k) {
    long double gamma = pi - (i + n - k) * theta / 2.0;
    return gamma;
  };
  auto update = [&](int i, int k) {
    if (k <= i) return;
    auto gamma = get(i, k);
    if (std::abs(gamma - aa) < std::abs(ans - aa)) {
      ans = gamma;
      ansi = i, ansk = k;
    }
  };
  for (int i = 2; i <= n; i++) {
    int l = i + 1, r = n, ans = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      auto gamma = get(i, mid);
      if (gamma > aa) r = mid - 1, ans = mid;
      else l = mid + 1;
    }
    update(i, ans);
    update(i, ans - 1);
  }
  std::cout << ansi << ' ' << j << ' ' << ansk << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
