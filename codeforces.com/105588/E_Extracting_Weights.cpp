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
 * @Author : iliyian
 * @File   : E_Extracting_Weights.cpp
 * @Time   : 2025-10-21 02:29:55
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> dfn(n + 1);
  int tot = 0;
  [&](this auto &&self, int u, int p) -> void {
    dfn[u] = ++tot;
    for (int v : g[u]) {
      if (v != p) {
        self(v, u);
      }
    }
  } (1, 0);
  std::vector<std::bitset<251>> v(n + 1), ori = {std::bitset<251>{}};
  auto insert = [&](std::bitset<251> bs) {
    for (int i = 1; i <= n; i++) {
      if (bs[i]) {
        if (v[i].none()) {
          v[i] = bs;
          return true;
        }
        bs ^= v[i];
      }
    }
    return false;
  };
  tot = 0;
  std::vector<std::pair<int, int>> ask;
  std::bitset<251> bs;
  bs.set(1);
  ori.push_back(bs);
  insert(bs);
  for (int i = 1; i <= n; i++) {
    auto dfs = [&](auto self, int u, int p, int dep, std::bitset<251> bs) -> void {
      bs[u] = 1;
      if (dep == k) {
        if (dfn[u] > dfn[i] && insert(bs)) {
          ori.push_back(bs);
          ask.push_back({i, u});
        }
        return;
      }
      for (int v : g[u]) {
        if (v != p) {
          self(self, v, u, dep + 1, bs);
        }
      }
    };
    dfs(dfs, i, 0, 0, std::bitset<251>{});
  }
  if (ask.size() == n - 1) {
    std::cout << "YES\n";
    std::cout << "? " << n - 1 << ' ';
    for (auto [x, y] : ask) {
      std::cout << x << ' ' << y << ' ';
    }
    std::cout << std::endl;
  } else {
    std::cout << "NO\n";
    return;
  }
  std::vector<int> a(n + 1);
  a[1] = 0;
  for (int i = 2; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int k = i;
    while (k <= n && ori[k][i] == 0) k++;
    std::swap(ori[k], ori[i]);
    std::swap(a[k], a[i]);
    for (int j = 1; j <= n; j++) {
      if (j != i) {
        if (ori[j][i]) {
          a[j] ^= a[i];
          ori[j] ^= ori[i];
        }
      }
    }
  }
  std::cout << "! ";
  for (int i = 2; i <= n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << std::endl;
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
