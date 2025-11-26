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
 * @File    : E_Journey.cpp
 * @Time    : 2025-11-07 12:22:08
 * @Comment : 好吧，昨天简单看了群里，还以为和Kruskal重构树没啥关系，
    但这个把边变成点好像还跟Kruskal重构树挺像的，相当于已经帮你排序好了，建个树，
    然后欧拉路一下，两个奇度数点可以在lca及其祖先上的权值相连，然后简单dp一下即可，
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + m);
  std::vector<int> pa(n + m), siz(n + m, 1);
  std::ranges::iota(pa, 0);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  int tot = n - 1, ans = 0;
  std::vector<int> W(n + m), deg(n + m);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    ans += w;
    x--, y--;
    deg[x] ^= 1, deg[y] ^= 1;
    x = find(x), y = find(y);
    if (x == y) {
      W[x] = std::min(W[x], w);
    } else {
      ++tot;
      g[tot].push_back(x);
      g[tot].push_back(y);
      W[tot] = w;
      pa[x] = pa[y] = pa[tot];
    }
  }
  [&](this auto &&self, int u) -> void {
    if (u < n) {

      return;
    }
    for (int v : g[u]) {
      W[v] = std::min(W[v], W[u]);
      self(v);
      deg[u] += deg[v];
    }
    if (deg[u] >= 2) {
      ans += deg[u] / 2 * W[u];
      deg[u] %= 2;
    }
  } (tot);
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
