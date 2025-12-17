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
 * @File    : C_Decryption.cpp
 * @Time    : 2025-12-16 20:46:00
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> div;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      div.push_back(i);
      if (i * i != n) {
        div.push_back(n / i);
      }
    }
  }
  div.push_back(n);
  // if (div.size() == 1) {
  //   return;
  // }
  std::ranges::sort(div);
  int m = div.size();

  if (m == 3) {
    for (auto i : div) {
      std::cout << i << ' ';
    }
    std::cout << 1 << '\n';
    return;
  }

  // for (int i = 0; i < )
  std::cout << 0 << '\n';

  // std::vector<int> p(m);
  // std::ranges::iota(p, 0);
  // int ans = LLONG_MAX / 3;
  // auto ansp = p;
  // do {
  //   int sum = 0;
  //   for (int i = 0; i < m; i++) {
  //     if (std::gcd(div[p[i]], div[p[(i + 1) % m]]) == 1) {
  //       sum++;
  //     }
  //   }
  //   if (sum < ans) {
  //     ansp = p;
  //     ans = sum;
  //   }
  //   if (ans == 0) {
  //     break;
  //   }
  // } while (std::next_permutation(p.begin(), p.end()));
  // std::cerr << "for n = " << n << ", ";
  // std::cerr << "ans = " << ans << '\n';
  // for (auto i : ansp) {
  //   std::cerr << div[p[i]] << ' ';
  // }
  // std::cerr << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  // for (int i = 4; i <= t; i++) {
  //   solve(i);
  // }

  while (t--) {
    solve();
  }

  return 0;
}
