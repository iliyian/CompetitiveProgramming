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
 * @File    : BenzenE.cpp
 * @Time    : 2026-02-07 15:00:57
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  int x = 0;
  for (auto &i : a) std::cin >> i, x ^= i;
  std::vector<int> d(63), from(63, -1);
  auto add = [&](int x) -> bool {
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return true;
        }
      }
    }
    return false;
  };
  std::vector<int> d2(63), s(63);
  auto add2 = [&](int x, int idx) {
    int has = 0;
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        has ^= s[i]; // 过去异或了哪些位置上的，这是固定的，同时异或两次也会抵，只会有一次设置from
        if (d2[i]) {
          x ^= d2[i];
        } else {
          d2[i] = x;
          s[i] = has ^ (1ll << i);
          from[i] = idx;
          return;
        }
      }
    }
  };
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    b[i] ^= a[i];
    if (add(b[i])) {
      add2(b[i], i);
    }
  }
  int ans = 0;
  for (int i = 62; i >= 0; i--) {
    if (x >> i & 1) {
      ans ^= s[i]; // 实际上要异或哪些位置
      if (d[i]) {
        x ^= d[i];
      } else {
        std::cout << -1 << '\n';
        return;
      }
    }
  }
  std::set<int> real;
  for (int i = 62; i >= 0; i--) {
    if (ans >> i & 1) {
      real.insert(from[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (real.count(i)) {
      std::cout << (a[i] ^ b[i]) << ' ';
    } else {
      std::cout << a[i] << ' ';
    }
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
