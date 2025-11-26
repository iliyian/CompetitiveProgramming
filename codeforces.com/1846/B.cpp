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
 * @File    : B.cpp
 * @Time    : 2025-11-01 15:25:17
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::vector<std::string> a(3);
  for (int i = 0; i < 3; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < 3; i++) {
    bool flag = true;
    for (int j = 0; j < 3; j++) {
      if (a[i][j] != a[i][0]) {
        flag = false;
        break;
      }
    }
    if (flag && a[i][0] != '.') {
      std::cout << a[i][0] << '\n';
      return;
    }
  }
  for (int j = 0; j < 3; j++) {
    bool flag = true;
    for (int i = 0; i < 3; i++) {
      if (a[i][j] != a[0][j]) {
        flag = false;
        break;
      }
    }
    if (flag && a[0][j] != '.') {
      std::cout << a[0][j] << '\n';
      return;
    }
  }
  bool flag = true;
  for (int i = 0; i < 3; i++) {
    if (a[i][i] != a[0][0]) {
      flag = false;
      break;
    }
  }
  if (flag && a[0][0] != '.') {
    std::cout << a[0][0] << '\n';
    return;
  }
  flag = true;
  for (int i = 0; i < 3; i++) {
    if (a[2 - i][i] != a[2][0]) {
      flag = false;
      break;
    }
  }
  if (flag && a[2][0] != '.') {
    std::cout << a[2][0] << '\n';
    return;
  }
  std::cout << "DRAW\n";
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
