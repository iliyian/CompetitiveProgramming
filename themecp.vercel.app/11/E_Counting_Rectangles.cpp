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
 * @File    : E_Counting_Rectangles.cpp
 * @Time    : 2025-11-29 10:04:37
 * @Comment : 这玩意怎么会是dp呢？
 * ==============================================================================
*/

#include <bits/stdc++.h>
// #define int long long

using i64 = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<i64> ans(q + 1);
  std::vector<std::vector<std::array<int, 3>>> ask(1001);
  std::vector<std::vector<int>> hw(1001);
  for (int i = 1; i <= n; i++) {
    int h, w;
    std::cin >> h >> w;
    hw[h].push_back(w);
  }
  for (int i = 1; i <= q; i++) {
    int hs, ws, hb, wb;
    std::cin >> hs >> ws >> hb >> wb;
    ask[hs].push_back({ws, i, 1});
    ask[hb - 1].push_back({ws, i, -1});
    ask[hs].push_back({wb - 1, i, -1});
    ask[hb - 1].push_back({wb - 1, i, 1});
  }
  std::vector<i64> d(1001);
  auto add = [&](int x, int c) -> void {for (int i = x; i <= 1000; i += i & -i) d[i] += c;};
  auto query = [&](int x) -> i64 {i64 ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;};
  for (int h = 1; h <= 1000; h++) {
    for (auto w : hw[h]) {
      add(w, h * w);
    }
    for (auto [w, idx, sig] : ask[h]) {
      ans[idx] += sig * query(w);
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << ans[i] << '\n';
  }
  // std::cout << '\n';
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
