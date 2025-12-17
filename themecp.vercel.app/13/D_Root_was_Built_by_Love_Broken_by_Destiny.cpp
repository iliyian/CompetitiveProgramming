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
 * @File    : D_Root_was_Built_by_Love_Broken_by_Destiny.cpp
 * @Time    : 2025-12-03 18:58:52
 * @Comment : 难绷，第一发竟然漏了一个条件没判。总之还是一道细节题吧？感觉一路下来还是挺有意思的......这种图+计数估计也不太可能很难做......
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;
int fac[200001] {};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (m != n - 1) {
    std::cout << 0 << '\n';
    return;
  }
  std::vector<int> dep(n + 1), pre(n + 1);
  int c = 0;
  auto dfs = [&](this auto &&self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pre[u] = p;
    if (dep[u] > dep[c]) {
      c = u;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(v, u);
      }
    }
  };
  dfs(1, 0);
  int d = c;
  c = 0;
  dfs(d, 0);
  int ans = 1;
  std::vector<int> v, key(n + 1);
  // std::cerr << c << ' ' << d << '\n';
  while (c != d) {
    c = pre[c];
    if (c != d) {
      v.push_back(c);
      key[c] = 1;
    }
  }
  if (v.empty()) {
    ans = 1;
    assert(n == 2);
  } else if (v.size() == 1) {
    ans = fac[g[v.front()].size()];
  } else {
    for (int i = 0; i < v.size(); i++) {
      int u = v[i];
      for (int v : g[u]) {
        if (!key[v]) {
          if (g[v].size() >= 2) {
            std::cout << 0 << '\n';
            return;
          }
        }
      }
      if (i == 0 || i == v.size() - 1) {
        ans = ans * fac[g[u].size() - 1] % mod;
      } else {
        ans = ans * fac[g[u].size() - 2] % mod;
      }
    }
    ans = ans * 2 % mod;
  }
  ans = ans * 2 % mod;
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  fac[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
