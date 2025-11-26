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
 * @File    : d.cpp
 * @Time    : 2025-11-07 01:06:11
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::ofstream os("d.in");
  std::mt19937_64 rd(std::random_device{}());

  int t = 1;
  os << t << '\n';
  std::vector<int> a = {3,4,7,19,43,115,271,547,1153,2329};
  std::vector<int> b = {284593,657595,1416805,2903545,6914335,14468161,29197201,59771995,128216119,292016107};
  int l = a.back(), r = b.front();
  for (int i = l + 1; i <= r - 1; i++) {
    for (int j = i + 1; j <= r - 1; j++) {
      if (i % j % 2 == 0) {
        bool flag = true;
        // if (i % j % 2) {
        //   continue;
        // }
        for (auto x : a) {
          if (i % x % 2 == 0 || j % x % 2 == 0) {
            // flag = false;
            goto end;
            // break;
          }
        }
        for (auto x : b) {
          if (x % i % 2 == 0 || x % j % 2 == 0) {
            goto end;
            // flag = false;
            // break;
          }
        }
        if (flag) {
          std::cout << i << ' ' << j << '\n';
          return 0;
        }
        end:;
      }
    }
  }
  std::cout << "Not Found\n" << '\n';
  // std::vector<int> a = {3};
  // while (1) {
  //   for (int x = a.back() + 1;; x++) {
  //     if (x > (int)1e9) {
  //       goto end;
  //     }
  //     bool flag = true;
  //     for (auto i : a) {
  //       if (x % i % 2 == 0) {
  //         flag = false;
  //         break;
  //       }
  //     }
  //     if (flag) {
  //       a.push_back(x);
  //       break;
  //     }
  //   }
  // }
  // end:;
  // os << a.size() << '\n';
  // for (auto i : a) {
  //   os << i << ' ';
  // }
  // os << '\n';

  return 0;
}
