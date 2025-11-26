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
 * @File    : H_The_Third_Letter.cpp
 * @Time    : 2025-11-24 16:12:49
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int inf = LLONG_MAX / 3;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<int> dis(n + 1, inf), pa(n + 1), siz(n + 1, 1);
  std::ranges::iota(pa, 0);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, -w});
    merge(x, y);
  }
  std::queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    if (pa[i] == i) {
      q.push({dis[i] = 0, i});
    }
  }
  while (!q.empty()) {
    auto [d, u] = q.front(); q.pop();
    for (auto [v, w] : g[u]) {
      if (dis[v] == inf) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      } else if (dis[v] != dis[u] + w) {
        std::cout << "NO\n";
        return;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dis[i] == inf) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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
