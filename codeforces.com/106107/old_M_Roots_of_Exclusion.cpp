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
 * @File   : M_Roots_of_Exclusion.cpp
 * @Time   : 2025-10-17 19:09:45
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int rt = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i] == n) {
      rt = i;
    }
  }
  std::vector<int> vis(n);
  vis[rt] = 1;
  std::cout << rt << '\n';
  if (a[0] > 1) {
    for (int i = 1; i < a[0]; i++) {
      vis[i] = 1;
      std::cout << i << ' ' << 0 << '\n';
    }
  }
  std::vector<int> p(n);
  std::ranges::iota(p, 0);
  std::ranges::sort(p, [&](auto x, auto y) {
    return a[x] == a[y] ? x < y : a[x] < a[y];
  });
  int pre = 0;
  std::set<int> s;
  for (int i = 0; i < n; i++) {
    if (a[p[i]] > 0) {
      for (int j = i; j < n; j++) {
        if (p[j] == 0) continue;
        for (int k = a[pre] + 1; k < a[p[j]]; k++) {
          if (vis[k]) continue;
          if (k == p[j]) {
            continue;
          }
          std::cout << k << ' ' << p[j] << '\n';
          vis[k] = 1;
        }
        vis[p[j]] = 1;
        if (pre == p[j]) {
          continue;
        }
        std::cout << pre << ' ' << p[j] << '\n';
        pre = p[j];
      }
      break;
    }
  }
  vis[0] = 1;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      std::cout << rt << ' ' << i << '\n';
    }
  }
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
