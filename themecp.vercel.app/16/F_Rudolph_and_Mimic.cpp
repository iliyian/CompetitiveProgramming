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
 * @File    : F_Rudolph_and_Mimic.cpp
 * @Time    : 2025-12-09 11:21:32
 * @Comment : 屎题
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  auto read = [&]() {
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    return a;
  };
  auto kill = [&](std::vector<int> from, std::vector<int> &to) {
    int c1[10] {}, c2[10] {};
    for (int i = 0; i < from.size(); i++) {
      c1[from[i]]++;
      c2[to[i]]++;
    }
    int x = 0;
    for (int i = 1; i <= 9; i++) {
      if (c2[i] > c1[i]) {
        x = i;
        break;
      }
    }
    if (!x) {
      std::cout << "- 0" << std::endl;
      return false;
    }
    int k = 0;
    for (auto i : to) k += i != x;
    if (k == n - 1) {
      int pos = 0;
      for (int i = 0; i < to.size(); i++) {
        if (to[i] == x && from[i] != x) {
          std::cout << "! " << i + 1 << std::endl;
          return true;
        }
      }
      assert(false);
    }
    std::vector<int> b(n - k, x);
    std::cout << "- " << k << ' ';
    for (int i = 0; i < to.size(); i++) {
      if (to[i] != x) {
        std::cout << i + 1 << ' ';
      }
    }
    std::cout << std::endl;
    to = b;
    n -= k;
    return false;
  };
  auto a1 = read();
  std::vector<int> a2;
  std::cout << "- 0" << std::endl;
  for (int i = 0; i < 4; i++) {
    a2 = read();
    if (kill(a1, a2)) {
      return;
    }
    a1.swap(a2);
  }
  assert(false);
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
