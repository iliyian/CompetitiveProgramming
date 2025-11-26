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
 * @File    : E_Permutations_Harmony.cpp
 * @Time    : 2025-10-30 17:27:02
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

// (n+1)k/2

constexpr int mod = 1e9 + 9, base = 1e9 + 7;

void solve(int _t) {
  int n, k;
  std::cin >> n >> k;
  if (_t == 938) {
    std::cerr << n << ' ' << k << '\n';
  }
  if (n == 1) {
    if (k == 1) {
      std::cout << "YES\n";
      std::cout << 1 << '\n';
      return;
    } else {
      std::cout << "NO\n";
      return;
    }
  }
  if (n % 2 == 0 && k % 2 || k == 1) {
    std::cout << "NO\n";
    return;
  }
  int ps[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
  if (n <= 8 && (ps[n] < k || ps[n] == k + 1)) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  std::vector<int> p(n), vc1, vc2;
  std::ranges::iota(p, 1);
  int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
  std::set<int> s;
  if (k % 2) {
    for (int i = 1; i <= n; i++) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    for (int i = 0, v1 = (n + 1) / 2, v2 = n; i < n; i++) {
      if (i % 2) {
        std::cout << v2 << ' ';
        vc1.push_back(v2);
        h1 = h1 * base % mod + v2;
        h1 %= mod;
        v2--;
      } else {
        std::cout << v1 << ' ';
        vc1.push_back(v1);
        h1 = h1 * base % mod + v1;
        h1 %= mod;
        v1--;
      }
    }
    std::cout << '\n';
    for (int i = 0, v1 = n, v2 = (n + 1) / 2 - 1; i < n; i++) {
      if (i % 2) {
        std::cout << v2 << ' ';
        vc2.push_back(v2);
        h2 = h2 * base % mod + v2;
        h2 %= mod;
        v2--;
      } else {
        std::cout << v1 << ' ';
        vc2.push_back(v1);
        h2 = h2 * base % mod + v1;
        h2 %= mod;
        v1--;
      }
    }
    std::cout << '\n';
    k -= 3;
    std::next_permutation(p.begin(), p.end());
  }
  auto rvc1 = vc1;
  auto rvc2 = vc2;
  std::ranges::reverse(rvc1);
  std::ranges::reverse(rvc2);
  for (int i = 0; i < k;std::next_permutation(p.begin(), p.end())) {
    {
      if (p == vc1) continue;
      if (p == vc2) continue;
      if (p == rvc1) continue;
      if (p == rvc2) continue;
      for (auto i : p) {
        std::cout << i << ' ';
      }
      std::cout << '\n';
      for (auto i : p) {
        std::cout << n - i + 1 << ' ';
      }
      std::cout << '\n';
      i += 2;
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;
  // if (t == 1000) {
  //   for (int i = 1; i <= 938; i++) {
  //     int n, k;
  //     std::cin >> n >> k;
  //     if (i == 938) {
  //       std::cout << n << ' ' << k << '\n';
  //       return 0;
  //     }
  //   }
  // }

  for (int i = 1; i <= t; i++) {
    solve(i);
  }

  return 0;
}
