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
 * @File   : D_Find_the_Last_Number.cpp
 * @Time   : 2025-10-24 23:12:45
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int tot = 0;

int ask(int pos, int val) {
  ++tot;
  std::cout << "? " << pos << ' ' << val << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  int mx = std::__lg(n);
  std::vector<int> v(n - 1), s(n);
  std::ranges::iota(v, 1);
  std::ranges::iota(s, 1);
  int ans = 0;
  for (int i = mx; i >= 0; i--) {
  // for (int i = 0; i <= mx; i++) {
    if (s.size() == 1) break;
    // for (auto i : v) {
    //   std::cerr << i << ' ';
    // }
    // std::cerr << '\n';
    std::vector<int> l, r, ls, rs;
    // int lcnt = (1ll << i) - 1;
    // if (ans) {
    //   lcnt++;
    // }
    int lcnt = 0;
    for (int x : s) {
      if (x >> i & 1) {
        rs.push_back(x);
      } else {
        ls.push_back(x);
      }
    }
    // std::cerr << "0需要有" << lcnt << '\n';
    for (int x : v) {
      if (ask(x, 1ll << i) == 0) {
        l.push_back(x);
      } else {
        r.push_back(x);
      }
    }
    // std::cerr << "0有" << l.size() << ", 1有" << r.size() << '\n';
    if (l.size() != ls.size()) { // 0的数量不对
      v = l;
      s = ls;
      // assert(l.size() < lcnt);
      // std::cerr << "0不对\n";
    } else {
      v = r;
      s = rs;
      // ans |= 1ll << i;
      // std::cerr << "1不对\n";
    }
  }
  std::cout << "! " << s[0] << std::endl;
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
