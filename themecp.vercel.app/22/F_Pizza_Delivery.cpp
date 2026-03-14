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
 * @File    : F_Pizza_Delivery.cpp
 * @Time    : 2026-03-05 21:28:04
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int ax, ay, bx, by, n;
  std::cin >> n >> ax >> ay >> bx >> by;
  std::map<int, int> mxy, mny;
  std::vector<int> vx(n), vy(n);
  for (auto &i : vx) std::cin >> i, mxy[i] = LLONG_MIN / 3, mny[i] = LLONG_MAX / 3;
  for (auto &i : vy) std::cin >> i;
  for (int i = 0; i < n; i++) {
    mxy[vx[i]] = std::max(mxy[vx[i]], vy[i]);
    mny[vx[i]] = std::min(mny[vx[i]], vy[i]);
  }
  std::ranges::sort(vx);
  vx.erase(std::unique(vx.begin(), vx.end()), vx.end());
  int ans = bx - ax;
  std::map<int, int> f;
  f[ay] = 0;
  mxy[bx] = mny[bx] = by;
  vx.push_back(bx);
  for (int x : vx) {
    int ry = mxy[x], ly = mny[x];
    ans += ry - ly;
    std::map<int, int> g;
    for (auto [py, pval] : f) {
      if (!g.count(ry)) {
        g[ry] = pval + std::abs(py - ly);
      } else {
        g[ry] = std::min(g[ry], pval + std::abs(py - ly));
      }
      if (!g.count(ly)) {
        g[ly] = pval + std::abs(py - ry);
      } else {
        g[ly] = std::min(g[ly], pval + std::abs(py - ry));
      }
    }
    f = std::move(g);
  }
  std::cout << ans + f.begin()->second << '\n';
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
