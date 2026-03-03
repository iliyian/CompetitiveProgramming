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
 * @File    : F.cpp
 * @Time    : 2026-02-25 12:03:11
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#include <cassert>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  int s = (1 + n * n) * n * n / 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }
  int r1 = -1, r2 = -1, c1 = -1, c2 = -1;
  int s1 = -1, s2 = -1;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += a[i][j];
    }
    if (sum != s / n) {
      if (r1 == -1) r1 = i, s1 = sum;
      else if (r2 == -1) r2 = i, s2 = sum;
      else assert(false);
    }
  }
  for (int j = 1; j <= n; j++) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i][j];
    }
    if (sum != s / n) {
      if (c1 == -1) c1 = j, s1 = sum;
      else if (c2 == -1) c2 = j, s2 = sum;
      else assert(false);
    }
  }
  if (r1 == -1) {
    for (int r = 1; r <= n; r++) {
      if (s1 - s2 == (a[r][c1] - a[r][c2]) * 2) {
        r1 = r2 = r;
        break;
      }
    }
  }
  if (c1 == -1) {
    for (int c = 1; c <= n; c++) {
      if (s1 - s2 == (a[r1][c] - a[r2][c]) * 2) {
        c1 = c2 = c;
        break;
      }
    }
  }
  auto b = a;
  auto check = [&]() {
    for (int i = 1; i <= n; i++) {
      int sum = 0;
      for (int j = 1; j <= n; j++) {
        sum += b[i][j];
      }
      if (sum != s / n) {
        return false;
      }
    }
    for (int j = 1; j <= n; j++) {
      int sum = 0;
      for (int i = 1; i <= n; i++) {
        sum += b[i][j];
      }
      if (sum != s / n) {
        return false;
      }
    }
    return true;
  };
  std::swap(b[r1][c1], b[r2][c2]);
  if (!check()) {
    std::swap(c1, c2);
  }
  std::cout << r1 << ' ' << c1 << '\n' << r2 << ' ' << c2 << '\n';
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
