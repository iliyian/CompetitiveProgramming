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
 * @File    : 时不时使使用玉米加农炮掩饰害羞的邻座艾莉同学.cpp
 * @Time    : 2026-02-09 14:34:19
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int dx[] = {0, -1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, 0};
int dy[] = {-2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2};

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1)), sum(n + 1, std::vector<int>(m + 1));
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  std::set<std::array<int, 3>, std::greater<>> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int su = 0;
      for (int d = 0; d < 13; d++) {
        int x = i + dx[d], y = j + dy[d];
        if (in(x, y)) {
          su += a[x][y];
        }
      }
      s.insert({su, i, j});
      sum[i][j] = su;
    }
  }
  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    for (int d = 0; d < 13; d++) {
      int xx = x + dx[d], yy = y + dy[d];
      if (in(xx, yy)) {
        s.erase({sum[xx][yy], xx, yy});
        sum[xx][yy] += z;
        s.insert({sum[xx][yy], xx, yy});
      }
    }
    std::cout << s.begin()->at(1) << ' ' << s.begin()->at(2) << '\n';
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
