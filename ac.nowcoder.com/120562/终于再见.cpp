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
 * @File    : 终于再见.cpp
 * @Time    : 2026-02-05 15:31:47
 * @Comment : 很经典的O(\sqrt{n}(n+m))?
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  std::vector<int> cnt(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
    cnt[x]++, cnt[y]++;
  }
  std::vector<int> a = cnt;
  std::ranges::sort(a);
  a.erase(std::unique(a.begin(), a.end()), a.end());
  std::vector<int> ans(n, LLONG_MAX / 3), dis(n);
  for (int i = 0; i < a.size(); i++) {
    std::queue<std::pair<int, int>> q;
    std::ranges::fill(dis, LLONG_MAX / 3);
    for (int u = 0; u < n; u++) {
      if (cnt[u] > a[i]) {
        q.push({dis[u] = 0, u});
      }
    }
    while (!q.empty()) {
      auto [d, u] = q.front(); q.pop();
      for (int v : g[u]) {
        if (dis[v] > dis[u] + 1) { // 好吧，我发现自己还是更喜欢把普通bfs当作dijkstra来写
          q.push({dis[v] = dis[u] + 1, v});
        }
      }
    }
    for (int u = 0; u < n; u++) {
      if (cnt[u] == a[i]) {
        ans[u] = dis[u];
      }
    }
  }
  for (auto i : ans) std::cout << (i == LLONG_MAX / 3 ? -1 : i) << ' ';
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
