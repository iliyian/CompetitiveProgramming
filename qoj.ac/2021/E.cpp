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
 * @File    : E.cpp
 * @Time    : 2025-10-28 21:32:02
 * @Comment : 最遗憾的一集。
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int inf = LLONG_MAX / 3;

// void solve() {
void solve(int _t) {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> g(n);
  std::vector<int> col(n);
  for (auto &i : col) std::cin >> i;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
  }
  if (_t == 25) {
    std::cerr << n << ' ' << m << ' ' << k << '\n';
    for (auto i : col) {
      std::cerr << i << ' ';
    }
    std::cerr << '\n';
    for (int i = 0; i < n; i++) {
      for (int j : g[i]) {
        std::cerr << i << ' ' << j << '\n';
      }
    }
  }
  for (int c = 1; c <= 50; c++) {
    std::vector<int> vis(n), from(n);
    std::queue<std::array<int, 3>> q;
    for (int i = 0; i < n; i++) {
      if (col[i] == c) {
        q.push({1, i, i});
        vis[i] = 1;
        from[i] = i;
      }
    }
    while (!q.empty()) {
      auto [d, u, s] = q.front(); q.pop();
      if (d > 50) continue;
      for (int v : g[u]) {
        if (vis[v] == 0) {
          vis[v] = 1;
          from[v] = s;
          q.push({d + 1, v, s});
        } else if (vis[v] == 1 && from[v] != s) {
          vis[v] = 2;
          q.push({d + 1, v, s});
        }
        if (col[v] == c && v != s && d + 1 <= k) {
          std::cout << "NO\n";
          return;
        }
      }
    }
  }
  std::cout << "YES\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
  }

  return 0;
}
