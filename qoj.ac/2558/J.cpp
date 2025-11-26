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
 * @File    : J.cpp
 * @Time    : 2025-11-05 18:29:12
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  g[1].push_back(0);
  int log = std::__lg(n);
  std::vector<int> dep(n + 1);
  std::vector<std::vector<int>> pa(log + 1, std::vector<int>(n + 1)), f(log + 1, std::vector<int>(n + 1));
  [&](this auto &&self, int u, int p) -> void {
    pa[0][u] = p;
    dep[u] = dep[p] + 1;
    for (int i = 0; i < log; i++) {
      pa[i + 1][u] = pa[i][pa[i][u]];
    }
    for (int v : g[u]) { 
      if (v != p) {
        self(v, u);
      }
    }
  } (1, 0);
  [&](this auto &&self, int u, int p) -> void {
    if (g[u].size() == 1 && g[u].front() == p) return;
    for (int v : g[u]) {
      if (v != p) {
        self(v, u);
      }
    }

    int m = g[u].size();
    int mn1 = LLONG_MAX / 3, mn2 = LLONG_MAX / 3;
    for (int v : g[u]) {
      if (v == p) continue;
      if (c[v] < mn1) {
        mn2 = mn1;
        mn1 = c[v];
      } else if (c[v] < mn2) {
        mn2 = c[v];
      }
    }
    c[u] = std::min(c[u], mn1 + mn2);
    for (int v : g[u]) {
      if (v != p) {
        if (c[v] == mn1) {
          f[0][v] = mn2;
        } else {
          f[0][v] = mn1;
        }
      }
    }
  } (1, 0);
  [&](this auto &&self, int u, int p) -> void {
    for (int i = 0; i < log; i++) {
      f[i + 1][u] = f[i][u] + f[i][pa[i][u]];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(v, u);
      }
    }
  } (1, 0);
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (dep[y] >= dep[x]) {
      std::cout << -1 << '\n';
      continue;
    }
    int z = x, ans1 = 0, ans2 = 0;
    // while (dep[z] > dep[y]) {
    //   ans1 += f[0][z];
    //   z = pa[0][z];
    // }
    // z = x;
    for (int i = log; i >= 0; i--) {
      if (dep[pa[i][z]] >= dep[y]) {
        ans2 += f[i][z];
        z = pa[i][z];
      }
    }
    if (z != y) {
      std::cout << -1 << '\n';
      continue;
    }
    // std::cout << "ask: " << x << ' ' << y << '\n';
    // std::cout << ans1 << ' ';
    std::cout << ans2 << '\n';
    // if (ans1 != ans2) {
    //   assert(false);
    // }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.in", "r", stdin);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
