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
 * @File    : H.cpp
 * @Time    : 2025-12-21 00:20:39
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int h, w, T;
  std::cin >> h >> w >> T;
  std::vector<std::string> a(h + 1);
  std::vector<std::pair<int, int>> pos;
  std::map<std::pair<int, int>, int> idx;
  int sx, sy, gx, gy;
  for (int i = 1; i <= h; i++) {
    std::cin >> a[i];
    a[i] = "#" + a[i];
    for (int j = 1; j <= w; j++) {
      if (a[i][j] == 'o') {
        pos.push_back({i, j});
        idx[{i, j}] = pos.size();
      }
      if (a[i][j] == 'S') {
        sx = i, sy = j;
      }
      if (a[i][j] == 'G') {
        gx = i, gy = j;
      }
    }
  }
  pos.insert(pos.begin(), {sx, sy});
  pos.push_back({gx, gy});
  idx[{sx, sy}] = 0;
  idx[{gx, gy}] = pos.size() - 1;
  int m = pos.size();
  std::vector<std::vector<int>> dis(m, std::vector<int>(m, -1));
  auto in = [&](int x, int y) {
    return x >= 1 && x <= h && y >= 1 && y <= w;
  };
  for (int i = 0; i < pos.size(); i++) {
    auto pp = pos[i];
    int x = pp.first, y = pp.second;
    std::queue<std::pair<int, int>> q;
    dis[i][i] = 0;
    q.push({x, y});
    std::vector<std::vector<int>> dist(h + 1, std::vector<int>(w + 1, -1));
    dist[x][y] = 0;
    while (!q.empty()) {
      auto pp = q.front(); q.pop();
      int x = pp.first, y = pp.second;
      for (int d = 0; d < 4; d++) {
        int xx = x + dx[d], yy = y + dy[d];
        if (in(xx, yy) && a[xx][yy] != '#' && dist[xx][yy] == -1) {
          dist[xx][yy] = dist[x][y] + 1;
          q.push({xx, yy});
          if (a[xx][yy] != '.') {
            dis[i][idx[{xx, yy}]] = dist[xx][yy];
          }
        }
      }
    }
  }
  int mxS = 1 << m;
  std::vector<std::vector<int>> f(m, std::vector<int>(mxS, LLONG_MAX / 3));
  f[0][1] = 0;
  int tot = 0;
  for (int i = 1; i < mxS; i++) {
    for (int j = 0; j < m; j++) {
      if (i >> j & 1 ^ 1) {
        for (int k = 0; k < m; k++) {
          if (i >> k & 1) {
            tot++;
            if (dis[k][j] == -1) continue;
            f[j][i | (1 << j)] = std::min(f[j][i | (1 << j)], f[k][i] + dis[k][j]);
          }
        }
      }
    }
  }
  std::cerr << tot << '\n';
  int ans = -1;
  for (int i = 0; i < mxS; i++) {
    if ((i & 1) && (i >> (m - 1) & 1) && f[m - 1][i] <= T) {
      ans = std::max(ans, (int)__builtin_popcountll(i) - 2);
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int x, y;
  while (std::cin >> x >> y) {
    std::cout << std::gcd(x, y) << '\n';
  }
  return 0;

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
