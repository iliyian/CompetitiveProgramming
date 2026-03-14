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
 * @File    : F_Fragmented_Nim.cpp
 * @Time    : 2026-03-12 20:03:40
 * @Comment : 有趣的博弈，竟然不使用mex二使用!max
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::map<std::pair<int, int>, int> mp;

int get(int x, int y) {
  if (x == 0 && y == 0) return 0;
  if (x == 0) return y % 2;
  if (y == 0) return 1;
  if (mp.count({x, y})) return mp[{x, y}];
  if (get(x, y - 1) == 0 && (get(x - 1, y + 1) == 0 || get(x - 1, y) == 0)) {
    return mp[{x, y}] = 1;
  } else {
    return mp[{x, y}] = 0;
  }
}

void solve() {
  int n;
  std::cin >> n;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    if (val == 1) y++;
    else x++;
  }
  if (x > 0 && y % 2 == 0 || x == 0 && y % 2 == 1) {
    std::cout << "Alice\n";
  } else {
    std::cout << "Bob\n";
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // int n = 10;
  // for (int x = 0; x <= n; x++) {
  //   for (int y = 0; y <= n; y++) {
  //     std::cout << get(x, y) << ' ';
  //   }
  //   std::cout << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
