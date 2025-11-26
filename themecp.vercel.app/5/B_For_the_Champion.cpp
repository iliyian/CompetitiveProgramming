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
 * @File    : B_For_the_Champion.cpp
 * @Time    : 2025-11-21 19:59:27
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int sumx = 0, sumy = 0;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int ansx = -123, ansy = 1233;
std::vector<int> xs = {0}, ys = {0};

int getans() {
  int ans = LLONG_MAX / 3;
  for (int i = 0; i < xs.size(); i++) {
    ans = std::min(ans, std::abs(xs[i] - (sumx + ansx)) + std::abs(ys[i] - (sumy + ansy)));
  }
  return ans;
}

int getdir(char x) {
  if (x == 'U') return 0;
  if (x == 'D') return 1;
  if (x == 'L') return 2;
  if (x == 'R') return 3;
}

int ask(char dir, int k) {
  std::cout << "? " << dir << ' ' << k << std::endl;
  int d = getdir(dir);
  sumx += k * dx[d], sumy += k * dy[d];
  int ans;
  std::cin >> ans;
  // ans = getans();
  return ans;
}

void solve() {
  sumx = sumy = 0;
  int n;
  std::cin >> n;
  int d1 = LLONG_MAX, d2 = LLONG_MAX;
  int mx = 1e9;
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    d1 = std::min(d1, (x + mx) + (mx - y));
    d2 = std::min(d2, (mx - x) + (mx - y));
  }
  ask('U', mx);
  ask('U', mx);
  ask('L', mx);
  int d3 = ask('L', mx) - d1;
  ask('R', mx);
  ask('R', mx);
  ask('R', mx);
  int d4 = ask('R', mx) - d2;
  int y = (d3 + d4) / 2;
  int x = d4 + 2 * mx - y;
  std::cout << "! " << x - sumx << ' ' << y - sumy << std::endl;
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
