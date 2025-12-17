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
 * @File    : B_Rectangle_GCD.cpp
 * @Time    : 2025-12-16 18:22:54
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> a(2, std::vector<int>(n + 1));
  int log = std::__lg(n);
  std::vector<std::vector<std::vector<int>>> g(2, std::vector<std::vector<int>>(log + 1, std::vector<int>(n)));
  for (int t = 0; t < 2; t++) {
    for (int i = 1; i <= n; i++) {
      std::cin >> a[t][i];
      if (i >= 2) {
        g[t][0][i - 1] = std::abs(a[t][i] - a[t][i - 1]);
      }
    }
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < log; i++) {
      for (int j = 1; j + (1ll << i) <= n - 1; j++) {
        g[t][i + 1][j] = std::gcd(g[t][i][j], g[t][i][j + (1ll << i)]);
      }
    }
  }
  auto get = [&](int idx, int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::gcd(g[idx][len][l], g[idx][len][r - (1ll << len) + 1]);
  };
  while (q--) {
    int h1, h2, w1, w2;
    std::cin >> h1 >> h2 >> w1 >> w2;
    int g = a[0][h1] + a[1][w1];
    if (h2 > h1) {
      g = std::gcd(g, get(0, h1, h2 - 1));
    }
    if (w2 > w1) {
      g = std::gcd(g, get(1, w1, w2 - 1));
    }
    std::cout << g << '\n';
  }
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
