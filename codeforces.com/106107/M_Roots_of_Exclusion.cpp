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
 * @Time   : 2025-10-17 19:40:02
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
  std::vector<int> p(n);
  std::ranges::iota(p, 0);
  std::ranges::sort(p, [&](auto x, auto y) {
    return a[x] == a[y] ? x < y : a[x] < a[y];
  });
  std::cout << rt << '\n';
  std::vector<int> vis(n);
  int pre = 0;
  for (int i = 1; i < a[0]; i++) {
    std::cout << i << ' ' << 0 << '\n';
    vis[i] = 1;
  }
  vis[0] = 1;
  for (int i = 0; i < n; i++) {
    if (a[p[i]] > 0) {
      if (p[i] == 0) continue;
      // std::cerr << i << ' ' << p[i] << '\n';
      std::cout << p[i - 1] << ' ' << p[i] << '\n';
      vis[p[i]] = 1;
      for (int j = a[p[i - 1]]; j < a[p[i]]; j++) {
        if (!vis[j]) {
          std::cout << j << ' ' << p[i] << '\n';
          vis[j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      std::cout << i << ' ' << rt << '\n';
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
