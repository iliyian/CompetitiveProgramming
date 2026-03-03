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
 * @File    : 墨提斯的排列.cpp
 * @Time    : 2026-02-09 14:08:08
 * @Comment : 
 * ==============================================================================
*/

#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> ans((1 << n) + 1);
  auto work = [&](auto self, int l, int r, int dep) -> void {
    if (l == r) {
      ans[l] = 1;
      return;
    }
    int mid = (l + r) / 2;
    ans[mid] = dep;
    self(self, l, mid - 1, dep / 2);
    self(self, mid + 1, r, dep / 2);
  };
  work(work, 1, (1 << n) - 1, 1 << (n - 1));
  // for (int i = 0; i <= (1 << n) - 1; i++) {
  //   std::cout << ans[i] << ' ';
  // }
  int x = 0;
  std::cout << x << ' ';
  for (int i = 1; i <= (1 << n) - 1; i++) {
    x ^= ans[i];
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int n = 1; n <= 3; n++) {
  //   std::vector<int> p(1 << n);
  //   std::ranges::iota(p, 0);
  //   int ans = LLONG_MAX / 3;
  //   auto ansp = p;
  //   do {
  //     int now = 0;
  //     for (int i = 1; i < (1 << n); i++) {
  //       now += p[i] ^ p[i - 1];
  //     }
  //     if (ans > now) {
  //       ans = now;
  //       ansp = p;
  //     }
  //   } while (std::next_permutation(p.begin(), p.end()));
  //   std::cout << ans << '\n';
  //   for (auto i : ansp) {
  //     std::cout << i << ' ';
  //   }
  //   std::cout << '\n';
  // }

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
