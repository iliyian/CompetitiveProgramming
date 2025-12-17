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
 * @File    : D_Wishing_Cards.cpp
 * @Time    : 2025-12-06 17:34:26
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, K;
  std::cin >> n >> K;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> b = {0}, len = {0};
  int le = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > mx) {
      mx = a[i];
      b.push_back(i);
      len.push_back(0);
    }
  }
  int m = b.size() - 1;
  for (int i = 1; i <= m; i++) {
    len[i] = (i == m ? n + 1 : b[i + 1]) - b[i];
    b[i] = a[b[i]];
  }
  // for (int i = 1; i <= m; i++) {
  //   std::cerr << b[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 1; i <= m; i++) {
  //   std::cerr << len[i] << ' ';
  // }
  // std::cerr << '\n';
  std::vector<std::vector<std::vector<int>>> f(m + 1, std::vector<std::vector<int>>(K + 1, std::vector<int>(K + 1, LLONG_MIN / 3)));
  std::vector<std::vector<int>> g(m + 1, std::vector<int>(K + 1, LLONG_MIN / 3));
  f[0][0][0] = g[0][0] = 0;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= std::min(j, b[i]); k++) {
        f[i][j][k] = std::max(f[i - 1][j][k], g[i - 1][j - k]) + k * len[i];
        g[i][j] = std::max(g[i][j], f[i][j][k]);
        ans = std::max(ans, g[i][j]);
      }
    }
  }
  std::cout << ans << '\n';
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
