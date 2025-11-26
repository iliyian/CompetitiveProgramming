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
 * @Author : iliyian
 * @File   : F_Long_Journey.cpp
 * @Time   : 2025-10-08 16:28:05
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

// int f[51][10][2520] {};
std::vector<std::vector<std::vector<int>>> f(51, std::vector<std::vector<int>>(10, std::vector<int>(2520)));
// 慢了一倍是吧？

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(n);
  int lcm = 1;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    lcm = std::lcm(lcm, a[i]);
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < lcm; j++) {
      f[0][i][j] = ((j + 1) % a[i] != b[i]);
    }
  }
  for (int i = 1; i <= 50; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < lcm; k++) {
        int jj = (j + (1ll << (i - 1))) % n;
        int kk = (k + f[i - 1][j][k]) % lcm;
        f[i][j][k] = f[i - 1][j][k] + f[i - 1][jj][kk];
      }
    }
  }
  int ans = 0, now = 0;
  for (int i = 50; i >= 0; i--) {
    if (now + f[i][ans % n][now % lcm] < m) {
      now += f[i][ans % n][now % lcm];
      ans += 1ll << i;
    }
  }
  if (now == m - 1 && f[0][ans % n][now % lcm]) {
    std::cout << ans + 1 << '\n';
  } else {
    std::cout << -1 << '\n';
  }
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
