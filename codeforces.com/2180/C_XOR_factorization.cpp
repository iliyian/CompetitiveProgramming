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
 * @File    : C_XOR_factorization.cpp
 * @Time    : 2025-12-19 22:49:05
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
// void solve(int n, int k) {
  int n, k;
  std::cin >> n >> k;
  if (k % 2 == 1) {
    for (int i = 1; i <= k; i++) {
      std::cout << n << ' ';
    }
    std::cout << '\n';
  } else {
    int d = 63 - __builtin_clzll(n);
    std::vector<int> pos;
    std::vector<int> ans(k - 1, n);
    int val = 0;
    for (int i = d - 1; i >= 0; i--) {
      if (n >> i & 1) {
        pos.push_back(i);
      }
    }
    for (int i = 0; i < std::min(pos.size(), ans.size()); i++) {
      ans[i] ^= 1ll << pos[i];
      for (int j = pos[i] - 1; j >= 0; j--) {
        if (ans[i] >> j & 1 ^ 1) {
          ans[i] ^= 1ll << j;
        }
      }
    }
    for (auto i : ans) {
      val ^= i;
    }
    ans.push_back(n ^ val);
    int got = 0;
    for (auto i : ans) {
      got += i;
      std::cout << i << ' ';
    }
    std::cout << '\n';

    // // int n = 10, k = 4;
    // std::vector<int> v, ansv;
    // int anss = 0;
    // [&](this auto &&self) {
    //   if (v.size() == k) {
    //     int sum = 0, x = 0;
    //     for (auto i : v) {
    //       sum += i;
    //       x ^= i;
    //     }
    //     if (sum > anss && x == n) {
    //       anss = sum, ansv = v;
    //     }
    //     return;
    //   }
    //   for (int i = 0; i <= n; i++) {
    //     v.push_back(i);
    //     self();
    //     v.pop_back();
    //   }
    // } ();
    // for (auto i : ansv) {
    //   std::cerr << i << ' ';
    // }
    // std::cerr << '\n';
    // std::cerr << "correct=" << anss << ", got=" << got << '\n';
    // if (anss != got) {
    //   std::cerr << "!!!!! " << n << ' ' << k << '\n';
    //   assert(false);
    // }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  // for (int n = 30; n <= 30; n++) {
  //   for (int k = 4; k <= 4; k += 2) {
  //     solve(n, k);
  //   }
  // }

  while (t--) {
    solve();
  }

  return 0;
}
