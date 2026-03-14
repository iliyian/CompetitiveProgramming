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
 * @File    : M_Medical_Parity.cpp
 * @Time    : 2026-03-11 22:36:43
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s[2];
  std::cin >> s[0] >> s[1];
  int n = s[0].size();
  std::vector<std::array<int, 4>> f(n, {LLONG_MAX / 3, LLONG_MAX / 3, LLONG_MAX / 3, LLONG_MAX / 3});
  if (s[0][0] == s[1][0]) {
    f[0] = {0, LLONG_MAX / 3, LLONG_MAX / 3, 2};
  } else {
    f[0] = {LLONG_MAX / 3, 1, 1, LLONG_MAX / 3};
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      int p0 = s[0][i - 1] ^ (j >> 0 & 1) ^ '0';
      int p1 = s[1][i - 1] ^ (j >> 1 & 1) ^ '0';
      for (int k = 0; k < 4; k++) {
        int c0 = s[0][i] ^ (k >> 0 & 1) ^ '0';
        int c1 = s[1][i] ^ (k >> 1 & 1) ^ '0';
        if ((p1 ^ c0) == c1) {
          f[i][k] = std::min(f[i][k], f[i - 1][j] + __builtin_popcountll(k));
        }
      }
    }
  }
  std::cout << *std::ranges::min_element(f[n - 1]) << '\n';
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
