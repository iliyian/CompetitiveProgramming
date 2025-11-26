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
 * @File    : C.cpp
 * @Time    : 2025-11-04 03:16:37
 * @Comment : 要死了
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int a[1001][1001] {
  {0, 0, 1, 1, 2, 2, 0, 0, 1},
  {2, 1, 0, 2, 1, 0, 2, 1, 0},
  {1, 2, 2, 0, 0, 1, 1, 2, 2},
  {2, 1, 0, 2, 2, 1, 1, 0, 0},
  {2, 0, 1, 0, 1, 2, 0, 1, 2},
  {0, 2, 1, 1, 0, 0, 2, 2, 1},
  {0, 1, 2, 1, 0, 0, 2, 2, 1},
  {1, 0, 2, 0, 1, 2, 0, 1, 2},
  {1, 2, 0, 2, 2, 1, 1, 0, 0},
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  if (n % 3 && m % 3) {
    std::cout << "No\n";
    return;
  }
  if (n == 1 && m == 3) {
    std::cout << "Yes\n012\n";
    return;
  }
  if (n == 3 && m == 1) {
    std::cout << "Yes\n0\n1\n2\n";
    return;
  }
  if (n == 2 && m == 3) {
    std::cout << "Yes\n012\n012\n";
    return;
  }
  if (n == 3 && m == 2) {
    std::cout << "Yes\n00\n11\n22\n";
    return;
  }
  if (n == 1 && m == 6) {
    std::cout << "Yes\n001122\n";
    return;
  }
  if (n == 6 && m == 1) {
    std::cout << "Yes\n0\n0\n1\n1\n2\n2\n";
    return;
  }
  if (n == 2 && m == 6) {
    std::cout << "Yes\n001122\n001122\n";
    return;
  }
  if (n == 6 && m == 2) {
    std::cout << "Yes\n00\n00\n11\n11\n22\n22\n";
    return;
  }
  if (std::min(n, m) < 3) {
    std::cout << "No\n";
    return;
  }
  bool f = false;
  std::cout << "Yes\n";
  if (n % 3 || m == 3) {
    std::swap(n, m);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        std::cout << a[i][j];
      }
      std::cout << '\n';
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << a[i][j];
    }
    std::cout << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 0; i < 9; i++) {
    for (int j = 9; j <= 1000; j++) {
      a[i][j] = a[i][j - 6];
    }
  }
  for (int i = 9; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      a[i][j] = a[i - 6][j];
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
