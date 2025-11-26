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
 * @File    : B.cpp
 * @Time    : 2025-11-02 14:53:57
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, H;
  std::cin >> n >> m >> H;
  std::vector<int> h(n);
  for (int i = 0; i < n; i++) {
    std::cin >> h[i];
  }
  std::vector<std::vector<std::pair<int, int>>> g(n);
  for (int i = 1; i <= m; i++) {
    int x, y, t;
    std::cin >> x >> y >> t;
    x--, y--;
    g[x].push_back({y, t});
    g[y].push_back({x, t});
  }
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  std::vector<std::vector<int>> dis(n, std::vector<int>(H + 1, LLONG_MAX / 3));
  q.push({dis[0][0] = 0, 0, 0});
  while (!q.empty()) {
    auto [d, _h, u] = q.top(); q.pop();
    for (auto [v, w] : g[u]) {
      int _hh = _h + std::max(0ll, h[v] - h[u]);
      if (h[v] < h[u]) {
        _hh = 0;
      }
      if (_hh > H) continue;
      if (dis[v][_hh] > dis[u][_h] + w) {
        dis[v][_hh] = dis[u][_h] + w;
        q.push({dis[v][_hh], _hh, v});
      }
    }
  }
  for (int i = 1; i < n; i++) {
    auto ans = *std::ranges::min_element(dis[i]);
    std::cout << (ans == LLONG_MAX / 3 ? -1 : ans) << ' ';
  }
  std::cout << '\n';
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
