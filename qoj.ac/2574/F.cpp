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
 * @File    : F.cpp
 * @Time    : 2025-11-10 22:02:01
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int mxS = 4096;
  std::vector<std::vector<int>> pa(mxS, std::vector<int>(n));
  std::vector<std::vector<int>> siz(mxS, std::vector<int>(n, 1));
  std::vector<int> pa2(n), siz2(n, 1);
  std::ranges::iota(pa2, 0);
  auto f = [&](this auto &&self, int x) -> int {return x == pa2[x] ? x : pa2[x] = self(pa2[x]);};
  auto me = [&](int x, int y) -> bool {
    x = f(x), y = f(y);
    if (x == y) return false;
    if (siz2[x] > siz2[y]) std::swap(x, y);
    pa2[x] = y;
    siz2[y] += siz2[x];
    return true;
  };
  for (int i = 0; i < mxS; i++) {
    std::ranges::iota(pa[i], 0);
  }
  auto find = [&](this auto &&self, int w, int x) -> int {return x == pa[w][x] ? x : pa[w][x] = self(w, pa[w][x]);};
  auto merge = [&](int w, int x, int y) {
    x = find(w, x), y = find(w, y);
    if (x == y) {
      return false;
    }
    if (siz[w][x] > siz[w][y]) std::swap(x, y);
    pa[w][x] = y;
    siz[w][y] += siz[w][x];
    return true;
  };
  int sum = 0;
  while (m--) {
    char op;
    std::cin >> op;
    if (op == '+') {
      int u, v, w;
      std::cin >> u >> v >> w;
      u--, v--;
      me(u, v);
      int ww = 0;
      std::vector<int> ve;
      for (int i = 11; i >= 0; i--) {
        if (w >> i & 1) {
          ve.push_back(i);
        }
      }
      int st = ve.size(), s = 0;
      for (int i = 0; i < ve.size(); i++) {
        s |= 1 << ve[i];
        if (!merge(s, u, v)) {
          break;
        }
        for (int j = i + 1; j < ve.size(); j++) {
          if (ve[j])
        }
      }
    } else {
      int u, v;
      std::cin >> u >> v;
      u--, v--;
      if (f(u) != f(v)) {
        sum += -1;
        std::cerr << -1 << '\n';
        continue;
      }
      int ans = 0;
      for (int i = 11; i >= 0; i--) {
        if (find(ans | (1 << i), u) == find(ans | (1 << i), v)) {
          ans |= 1 << i;
        }
      }
      sum += ans;
      std::cerr << ans << '\n';
    }
  }
  std::cout << sum << '\n';
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
