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
 * @File    : D_Traffic_Lights.cpp
 * @Time    : 2025-11-07 18:25:52
 * @Comment : 大佬的实现总是令人受益匪浅！！！！本题看似最短路，实际上是最短等待时间
     不妨大胆猜测（虽然也可以证），最短等待时间不会太大，然后直接枚举等待时间，
     在while里面，类似图上dp的写法实在太tmd酷了，甚至滚动数组
     哎，是这样的，我好像总是避免写无向图上dp，都是用队列来替代，但是大佬实在是太厉害了
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int inf = LLONG_MAX / 3;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> f(n, inf);
  f[0] = 0;
  int t = 0;
  while (f[n - 1] >= inf) {
    std::vector<int> nf(n, inf);
    for (int u = 0; u < n; u++) {
      nf[u] = f[u] + 1;
    }
    for (int u = 0; u < n; u++) {
      nf[g[u][t % g[u].size()]] = std::min(nf[g[u][t % g[u].size()]], f[u]);
    }
    f.swap(nf);
    t++;
  }
  std::cout << t << ' ' << f[n - 1] << '\n';
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