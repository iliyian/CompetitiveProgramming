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
 * @File    : 收买时间.cpp
 * @Time    : 2026-03-13 19:13:16
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m, money, k;
  std::cin >> n >> m >> money >> k;
  std::vector<std::vector<int>> t(n + 1, std::vector<int>(m + 1));
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> t[i][j];
      mx = std::max(mx, t[i][j]);
    }
  }
  std::vector<std::vector<std::vector<std::array<int, 3>>>> g(n + 1, std::vector<std::vector<std::array<int, 3>>>(m + 1));
  for (int i = 1; i <= k; i++) {
    int x, y, p, q, w;
    std::cin >> x >> y >> p >> q >> w;
    g[x][y].push_back({p, q, w});
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  auto id = [&](int x, int y) {
    return (x - 1) * m + y;
  };
  auto check = [&](int mid) -> bool {
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
    std::vector<std::vector<int>> dis(n + 1, std::vector<int>(m + 1, LLONG_MAX / 3));
    q.push({dis[1][1] = 0, 1, 1});
    while (!q.empty()) {
      auto [d, x, y] = q.top(); q.pop();
      if (dis[x][y] != d) continue;
      if (d > money) return false;
      if (x == n && y == m) {
        return true;
      }
      for (int d = 0; d < 4; d++) {
        int xx = x + dx[d], yy = y + dy[d];
        if (in(xx, yy) && t[xx][yy] <= mid && dis[xx][yy] > dis[x][y]) {
          q.push({dis[xx][yy] = dis[x][y], xx, yy});
        }
      }
      for (auto &[xx, yy, w] : g[x][y]) {
        if (t[xx][yy] <= mid && dis[xx][yy] > dis[x][y] + w) {
          q.push({dis[xx][yy] = dis[x][y] + w, xx, yy});
        }
      }
    }
    return false;
  };
  int ans = -1, l = 0, r = mx;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << ans << '\n';
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
