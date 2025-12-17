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
 * @File    : B_Time_Travel.cpp
 * @Time    : 2025-12-03 19:34:14
 * @Comment : 刺激！酣畅淋漓的体验！我图论应该可以跟雷神相提并论了！（2333333
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, t;
  std::cin >> n >> t;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= t; i++) {
    int m;
    std::cin >> m;
    for (int j = 1; j <= m; j++) {
      int x, y;
      std::cin >> x >> y;
      g[x].push_back({i, y});
      g[y].push_back({i, x});
    }
  }
  int k;
  std::cin >> k;
  std::vector<std::vector<int>> available(t + 1);
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    available[x].push_back(i);
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  std::vector<int> dis(n + 1, LLONG_MAX / 3);
  q.push({dis[1] = 1, 1});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (dis[u] != d) continue;
    for (auto [w, v] : g[u]) {
      auto p = std::ranges::lower_bound(available[w], d);
      if (p != available[w].end()) {
        if (dis[v] > *p + 1) {
          dis[v] = *p + 1;
          q.push({dis[v], v});
        }
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << dis[i] << ' ';
  // }
  // std::cerr << '\n';
  std::cout << (dis[n] == LLONG_MAX / 3 ? -1 : dis[n] - 1) << '\n';
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
