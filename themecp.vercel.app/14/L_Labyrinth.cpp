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
 * @File    : L_Labyrinth.cpp
 * @Time    : 2025-12-05 13:34:33
 * @Comment : 这题抛开实现上的细节，做法是相当显然的。怎么有1800呢？
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, s;
  std::cin >> n >> m >> s;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  std::vector<int> pre(n + 1), id(n + 1);
  int tot = 0;
  bool found = false;
  std::vector<int> ans1, ans2;
  auto dfs = [&](this auto &&self, int u, int p, int idx) -> void {
    if (u == s) return;
    if (pre[u]) {
      if (id[u] == idx) {
      } else {
        found = true;
        int v = u;
        while (1) {
          ans2.push_back(v);
          if (v == s) break;
          v = pre[v];
        }
        std::ranges::reverse(ans2);
        ans1.push_back(u);
        v = p;
        while (1) {
          ans1.push_back(v);
          if (v == s) break;
          v = pre[v];
        }
        std::ranges::reverse(ans1);
      }
      return;
    }
    pre[u] = p;
    id[u] = idx;
    for (int v : g[u]) {
      self(v, u, idx);
      if (found) return;
    }
  };
  for (int v : g[s]) {
    dfs(v, s, ++tot);
    if (found) break;
  }
  if (found) {
    std::cout << "Possible\n";
    std::cout << ans1.size() << '\n';
    for (auto i : ans1) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    std::cout << ans2.size() << '\n';
    for (auto i : ans2) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  } else {
    std::cout << "Impossible\n";
  }
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
