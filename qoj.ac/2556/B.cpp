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
 * @File   : B.cpp
 * @Time   : 2025-10-18 19:10:13
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

int get(char c) {
  if (c == 'U') return 0;
  if (c == 'D') return 1;
  if (c == 'L') return 2;
  if (c == 'R') return 3;
  return -1;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string s;
  std::cin >> s;
  int sumx = 0, sumy = 0, lx = 0, rx = 0, ly = 0, ry = 0;
  std::set<std::pair<int, int>> st;
  st.insert({0, 0});
  std::vector<std::
  for (int i = 0; i < n; i++) {
    sumx += dx[get(s[i])], sumy += dy[get(s[i])];
    lx = std::min(lx, sumx);
    ly = std::min(ly, sumy);
    rx = std::max(rx, sumx);
    ry = std::max(ry, sumy);
    st.insert({sumx, sumy});
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (x > rx && sumx > 0 || x < lx && sumx < 0 || y > ry && sumy > 0 || y < ry && sumy < 0) {
    } else {
      
    }
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
