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
 * @File   : C.cpp
 * @Time   : 2025-10-15 17:46:10
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int l, r;
  std::cin >> l >> r;
  if (l % 2 == 1) {
    if (r >= l * 2) {
      std::cout << "Alice\n";
    } else {
      std::cout << (r % 2 == 1 ? "Alice" : "Bob") << '\n';
    }
  } else {
    if (r > l * 2) {
      std::cout << "Bob\n";
    } else {
      std::cout << (r % 2 == 0 ? "Alice" : "Bob") << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int l = 1; l <= 30; l++) {
  //   for (int r = l; r <= 30; r++) {
  //     std::set<int> s;
  //     for (int i = l; i <= r; i++) {
  //       s.insert(i);
  //     }
  //     auto work = [&](this auto &&self, int x) {
  //       if (x > r || s.empty()) return 0ll;
  //       for (int i = 1; i * x <= r; i++) {
  //         if (s.count(i * x)) {
  //           s.erase(i * x);
  //           bool ans = self(x + 1);
  //           s.insert(i * x);
  //           if (!ans) {
  //             return 1ll;
  //           }
  //         }
  //       }
  //       return 0ll;
  //     };
  //     std::cerr << l << ' ' << r << " = " << work(l) << '\n';
  //   }
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
