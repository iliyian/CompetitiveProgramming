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
 * @File    : 鱼骨挖矿法.cpp
 * @Time    : 2025-12-07 11:59:05
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n, m;
  std::cin >> n >> m;
  // n = rd() % 100 + 1, m = rd() % 100 + 1;
  std::vector<std::vector<int>> a(n + 10, std::vector<int>(m + 10));
  std::vector<std::vector<int>> pos(m + 10);
  std::vector<std::vector<int>> down(n + 10, std::vector<int>(m + 10, n + 2));
  std::vector<std::vector<int>> up(n + 10, std::vector<int>(m + 10, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      // a[i][j] = (a[i - 1][j] == 0 && a[i][j - 1] == 0 && rd() % 10 == 0 ? rd() % 10 : 0);
      if (a[i][j]) {
        pos[j].push_back(i);
        down[i][j] = i;
        up[i][j] = i;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = n - 1; i >= 1; i--) {
      down[i][j] = std::min(down[i][j], down[i + 1][j]);
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      up[i][j] = std::max(up[i][j], up[i - 1][j]);
    }
  }
  auto work = [&](int r) {
    int ans = 0;
    for (int j = 1; j <= m; j++) {
      ans += a[r][j] + a[r - 1][j] + a[r + 1][j];
    }
    for (int j = 2; j <= m; j += 3) {
      int d = down[r + 2][j], dl = down[r + 2][j - 1], dr = down[r + 2][j + 1];
      d = std::min({d - 1, dl, dr});
      if (d == r + 1) {
        ans += a[d + 1][j];
      } else {
        // std::cerr << d << ' ' << j << ' ' << n << ' ' << m << std::endl;
        ans += a[d + 1][j] + a[d][j - 1] + a[d][j + 1];
      }
      if (r < 2) continue;
      int u = up[r - 2][j], ul = up[r - 2][j - 1], ur = up[r - 2][j + 1];
      u = std::max({u + 1, ul, ur});
      if (u == r - 1) {
        ans += a[u - 1][j];
      } else {
        ans += a[u - 1][j] + a[u][j - 1] + a[u][j + 1];
      }
    }
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    std::cout << work(i) << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.out", "w", stdout);

  int t = 1;
  std::cin >> t;
  // t = 1000;

  while (t--) {
    solve();
  }

  return 0;
}
