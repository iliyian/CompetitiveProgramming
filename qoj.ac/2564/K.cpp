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
 * @File    : K.cpp
 * @Time    : 2025-11-02 15:38:21
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int x;
    std::cin >> x;
    x--;
    g[x].push_back(i);
  }
  std::vector<int> siz(n), dep(n);
  dep[0] = 1;
  int ans1 = 0, ans2 = 0;
  [&](this auto &&self, int u, int p) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        dep[v] = dep[u] + 1;
        self(v, u);
        siz[u] += siz[v];
      }
    }
    std::ranges::sort(g[u], [&](auto x, auto y) {
      return siz[x] > siz[y];
    });
  } (0, -1);
  [&](this auto &&self, int u, int p) -> void {
    ans1 += dep[u];
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (v != p) {
        dep[v] = dep[u] + i + 1;
        self(v, u);
      }
    }
  } (0, -1);
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
