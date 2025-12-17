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
 * @File    : E_两只塔姆沃斯牛_The_Tamworth_Two.cpp
 * @Time    : 2025-12-06 18:29:41
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  std::vector<std::string> s(10);
  int fx, fy, cx, cy, fd = 0, cd = 0;
  for (int i = 0; i < 10; i++) {
    std::cin >> s[i];
    for (int j = 0; j < 10; j++) {
      if (s[i][j] == 'F') fx = i, fy = j;
      if (s[i][j] == 'C') cx = i, cy = j;
    }
  }
  auto move = [&](this auto &&self, int &x, int &y, int &d) -> void {
    int xx = x + dx[d], yy = y + dy[d];
    if (xx >= 0 && xx < 10 && yy >= 0 && yy < 10 && s[xx][yy] != '*') x = xx, y = yy;
    else d = (d + 1) % 4;
  };
  auto work = [&]() {
    move(fx, fy, fd);
    move(cx, cy, cd);
    return fx != cx || fy != cy;
  };
  int ans = 0;
  while (work()) {
    // for (int i = 0; i < 10; i++) {
    //   for (int j = 0; j < 10; j++) {
    //     if (i == cx && j == cy) {
    //       std::cout << 'C';
    //     } else if (i == fx && j == fy) {
    //       std::cout << 'F';
    //     } else if (s[i][j] != '*') {
    //       std::cout << '.';
    //     } else {
    //       std::cout << '*';
    //     }
    //   }
    //   std::cout << '\n';
    // }
    // std::cout << '\n';
    ans++;
    if (ans >= 100000) {
      std::cout << 0 << '\n';
      return;
    }
  }
  std::cout << ans + 1 << '\n';
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
