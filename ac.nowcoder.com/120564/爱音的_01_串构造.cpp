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
 * @File    : 爱音的_01_串构造.cpp
 * @Time    : 2026-02-09 14:57:52
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (a == 0) {
    for (int i = 0; i < b; i++) {
      std::cout << 1;
    }
    std::cout << '\n';
    return;
  }
  if (b == 0) {
    for (int i = 0; i < a; i++) {
      std::cout << 0;
    }
    std::cout << '\n';
    return;
  }
  int f = false;
  if (a < b) std::swap(a, b), f = 1;
  int l = a / (b + 1), r = (a + b) / (b + 1);
  if (l == r) {
    for (int i = 0; i < b + 1; i++) {
      for (int j = 0; j < l; j++) {
        std::cout << f;
      }
      if (i != b) {
        std::cout << (f ^ 1);
      }
    }
    std::cout << '\n';
    return;
  }
  for (int i = 0; i < b + 1 - a % (b + 1); i++) {
    for (int j = 0; j < l; j++) {
      std::cout << f;
    }
    std::cout << (f ^ 1);
  }
  for (int i = 0; i < a % (b + 1) - 1; i++) {
    for (int j = 0; j < r; j++) {
      std::cout << f;
    }
    std::cout << (f ^ 1);
  }
  for (int j = 0; j < r; j++) {
    std::cout << f;
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int n = 13; n <= 13; n++) {
  //   std::vector<int> ans(n + 1, -1), ansn(n + 1, -1);
  //   for (int s = 0; s < (1 << n); s++) {
  //     int now = 0;
  //     for (int l = 0; l < n; l++) {
  //       int x[2] {};
  //       for (int r = l; r < n; r++) {
  //         x[s >> r & 1]++;
  //         if (x[0]) {
  //           if (x[1]) now += 2;
  //           else now += 1;
  //         }
  //       }
  //     }
  //     int cnt = __builtin_popcountll(s);
  //     if (ans[cnt] < now) {
  //       ans[cnt] = now;
  //       ansn[cnt] = s;
  //     }
  //   }
  //   for (int i = 0; i <= n; i++) {
  //     std::cout << ans[i] << ' ' << ansn[i] << ' ';
  //     for (int j = 0; j < n; j++) {
  //       std::cout << (ansn[i] >> j & 1);
  //     }
  //     std::cout << '\n';
  //   }
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
