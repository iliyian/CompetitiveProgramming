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
 * @File    : D_虫洞_wormhole.cpp
 * @Time    : 2025-12-04 18:22:46
 * @Comment : 好吧，果然简单的题，必定存在我能够写出来的简单的做法......
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    auto &[x, y] = a[i];
    std::cin >> x >> y;
  }
  std::sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
    return std::tie(x.second, x.first) < std::tie(y.second, y.first);
  });
  std::vector<int> mp(n + 1);
  int ans = 0;
  auto check = [&](this auto &&self, int id, bool trans, int from, bool begin) -> int {
    if (!trans && id == from && !begin) {
      return true;
    }
    if (!trans) {
      return self(mp[id], 1, from, false);
    } else {
      if (id == n || a[id + 1].second != a[id].second) {
        return false;
      }
      return self(id + 1, 0, from, false);
    }
  };
  [&](this auto &&self, int u) -> void {
    if (u == n + 1) {
      for (int i = 1; i <= n; i++) {
        if (check(i, 0, i, true)) {
          ans++;
          break;
        }
      }
      return;
    }
    if (mp[u]) {
      self(u + 1);
    } else {
      for (int i = u + 1; i <= n; i++) {
        if (!mp[i]) {
          mp[i] = u, mp[u] = i;
          self(u + 1);
          mp[i] = mp[u] = 0;
        }
      }
    }
  } (1);
  std::cout << ans << '\n';
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
