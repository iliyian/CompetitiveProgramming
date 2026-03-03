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
 * @File    : main.cpp
 * @Time    : 2025-12-31 19:51:23
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  auto in = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  auto id = [&](int x, int y, int t) {
    return t * n * m + x * m + y;
  };
  std::vector<std::vector<int>> g(n * m * 2);
  std::vector<int> deg(n * m * 2), ans(n * m * 2, 2);
  std::queue<int> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
      if (a[i][j] == 0) continue;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k] * a[i][j], y = j + dy[k] * a[i][j];
        if (in(x, y)) {
          for (int t = 0; t < 2; t++) {
            g[id(x, y, t)].push_back(id(i, j, t ^ 1));
            deg[id(i, j, t ^ 1)]++;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0 || i == n - 1 && j == m - 1) {
      } else {
        if (deg[id(i, j, 0)] == 0) {
          ans[i * m + j] = ans[i * m + j + n * m] = 0;
          q.push(id(i, j, 0));
          q.push(id(i, j, 1));
        } 
      }
    }
  }
  q.push(0);
  q.push(n * m - 1);
  q.push(n * m);
  q.push(2 * n * m - 1);
  ans[0] = 1;
  ans[n * m - 1] = 0;
  ans[n * m] = 0;
  ans[2 * n * m - 1] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int t = u / (n * m), x = u % (n * m) / m, y = u % m;
    for (int v : g[u]) {
      int tt = v / (n * m), xx = v % (n * m) / m, yy = v % m;
      if (ans[v] == 2) {
        if (ans[u] == 0) {
          ans[v] = 1;
          deg[v] = 0;
          q.push(v);
        } else if (ans[u] == 1) {
          if (!--deg[v]) {
            ans[v] = 0;
            q.push(v);
          }
        }
      }
    }
  }
  for (int i = 0; i < n * m * 2; i++) {
    if (i < n * m) {
      std::cout << (ans[i] == 1 ? 'P' : ans[i] == 0 ? 'B' : 'T');
    } else {
      std::cout << (ans[i] == 0 ? 'P' : ans[i] == 1 ? 'B' : 'T');
    }
    if (i % m == m - 1) {
      std::cout << '\n';
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
