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
 * @File    : 最大化仿射变换.cpp
 * @Time    : 2025-11-30 13:30:55
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::tuple<int, int, double>> op;
  int x = 0;
  for (int i = 1; i <= n; i++) {
    int a, b;
    std::cin >> a >> b;
    op.push_back({a, b, a == 1 ? INT_MAX / 3 + b : 1.0 * b / (a - 1)});
  }
  std::ranges::sort(op, [&](auto x, auto y) {
    if (std::get<0>(x) == 0 && std::get<0>(y) == 0) {
      return std::get<1>(x) < std::get<1>(y);
    }
    if (std::get<0>(x) == 0 || std::get<0>(y) == 0) {
      return std::get<0>(x) == 0;
    }
    return std::get<2>(x) > std::get<2>(y);
  });
  for (auto [a, b, v] : op) {
    // std::cerr << a << ' ' << b << ' ';
    x = (x * a % mod + b) % mod;
    // std::cerr << (a == 1 ? -111 : 1.0 * b / (a - 1)) << '\n';
  }
  // int ans;
  // std::cin >> ans;
  // std::cout << x << ' ' << ans << '\n';
  std::cout << x << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.in", "r", stdin);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
