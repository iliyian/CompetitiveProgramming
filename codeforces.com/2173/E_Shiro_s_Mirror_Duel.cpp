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
 * @File    : E_Shiro_s_Mirror_Duel.cpp
 * @Time    : 2025-12-06 12:01:19
 * @Comment : 傻逼软工课设，sbjj，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，傻逼课设，
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), pos(n);
  for (auto &i : a) std::cin >> i, i--;
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  auto ask = [&](int l, int r) {
    std::cout << "? " << l + 1 << ' ' << r + 1 << std::endl;
    int x, y;
    int p = rd() % 2;
    // if (p) x = l + 1, y = r + 1;
    // else x = n - r, y = n - l;
    // std::cout << x << ' ' << y << std::endl;
    std::cin >> x >> y;
    x--, y--;
    std::swap(pos[a[x]], pos[a[y]]);
    std::swap(a[x], a[y]);
    return std::pair{x, y};
  };
  int i = 0;
  while (i < n - i - 1) {
    if (pos[i] == i && pos[n - i - 1] == n - i - 1) {
      i++;
      continue;
    }
    if (pos[i] != i) {
      ask(i, pos[i]);
      continue;
    }
    ask(n - i - 1, pos[n - i - 1]);
  }
  std::cout << "!" << std::endl;
  // for (int i = 0; i < n; i++) {
  //   std::cout << a[i] + 1 << ' ';
  // }
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
