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
 * @File    : B_Shortest_Statement_Ever.cpp
 * @Time    : 2026-03-03 22:43:42
 * @Comment : shitty
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::array<int, 3> f[61][3][3] {};

void solve() {
  int x, y;
  std::cin >> x >> y;
  for (int i = 0; i < 61; i++) {
    for (int p = 0; p < 3; p++) {
      for (int q = 0; q < 3; q++) {
        f[i][p][q] = {LLONG_MIN / 3, -1, -1};
      }
    }
  }
  auto work = [&](auto self, int idx, int ps, int qs) -> std::array<int, 3> {
    if (idx == -1) {
      return {0, 0, 0};
    }
    if (f[idx][ps][qs][0] != LLONG_MIN / 3)  return f[idx][ps][qs];
    int ans = LLONG_MAX / 3;
    int _ansp = -1, _ansq = -1;
    for (auto p : {0, 1}) {
      for (auto q : {0, 1}) {
        if (p & q) continue;
        int ix = x >> idx & 1, iy = y >> idx & 1;
        int now = 0;
        int nps = -1, nqs = -1;
        auto wk = [&](int iv, int v, int s, int &t) {
          if (s == 0) {
            if (iv == v) {
              t = 0;
            } else if (iv > v) {
              t = 1;
            } else {
              t = 2;
            }
          } else {
            t = s;
          }
          if (t == 1) {
            now += (iv - v) << idx;
          } else {
            now += (v - iv) << idx;
          }
        };
        wk(ix, p, ps, nps);
        wk(iy, q, qs, nqs);
        auto [nxt, _, __] = self(self, idx - 1, nps, nqs);
        if (now + nxt < ans) {
          ans = now + nxt;
          _ansp = p << idx | _, _ansq = q << idx | __;
        }
      }
    }
    return f[idx][ps][qs] = {ans, _ansp, _ansq};
  };
  auto [ans, ansx, ansy] = work(work, 60, 0, 0);
  std::cout << ansx << ' ' << ansy << '\n';
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
