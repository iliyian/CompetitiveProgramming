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
 * @File    : F_Beautiful_Intervals.cpp
 * @Time    : 2025-10-28 15:47:54
 * @Comment : 什么诈骗题，果然过于复杂的操作与维护往往实际上就是不可能的吗（）
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n, -1), pre(n + 1);
  std::vector<std::pair<int, int>> v(m);
  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r;
    pre[l - 1]++, pre[r]--;
    v[i] = {l, r};
  }
  for (int i = 0; i < n; i++) {
    pre[i + 1] += pre[i];
  }
  for (int i = 0; i < n; i++) {
    if (pre[i] == m) {
      std::cout << i << ' ';
      for (int j = 1; j < n; j++) {
        if (j == i) {
          std::cout << 0 << ' ';
        } else {
          std::cout << j << ' ';
        }
      }
      std::cout << '\n';
      return;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < 2; j++) {
      bool flag = true;
      for (auto [l, r] : v) {
        l--, r--;
        if (i >= l && i + 1 <= r || i + j < l || i + j > r) {
        } else {
          flag = false;
          break;
        }
      }
      if (flag) {
        a[i] = j, a[i + 1] = j ^ 1;
        int tot = 1;
        for (auto &i : a) {
          if (i == -1) i = ++tot;
          std::cout << i << ' ';
        }
        std::cout << '\n';
        return;
      }
    }
  }
  std::cout << "1 2 0 ";
  for (int j = 3; j < n; j++) {
    std::cout << j << ' ';
  }
  std::cout << '\n';
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
