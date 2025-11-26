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
 * @File    : B_Integers_Have_Friends.cpp
 * @Time    : 2025-11-01 16:05:08
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int gcd(int a, int b) {
  return std::gcd(a, b);
  // if (!a | !b) return a + b;
  // int az = __builtin_ctzll(a);
  // int bz = __builtin_ctzll(b);
  // int z = std::min(az, bz);
  // a >>= az, b >>= bz;
  // while (a != b) {
  //   int diff = b - a;
  //   az = __builtin_ctzll(diff);
  //   b = std::min(a, b), a = std::abs(diff) >> az;
  // }
  // return a << z;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int log = std::__lg(n);
  std::vector<std::vector<int>> st(log + 1, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (i) {
      st[0][i - 1] = std::abs(a[i] - a[i - 1]);
    }
  }
  for (int i = 0; i < log; i++) {
    for (int j = 0; j + (1 << i) < n; j++) {
      st[i + 1][j] = gcd(st[i][j], st[i][j + (1 << i)]);
    }
  }
  auto get = [&](int l, int r) {
    int log = std::__lg(r - l + 1);
    return gcd(st[log][l], st[log][r - (1 << log) + 1]);
  };
  auto check = [&](int mid) -> bool {
    for (int i = 0; i + mid - 2 < n - 1; i++) {
      int r = i + mid - 2;
      if (get(i, r) >= 2) {
        return true;
      }
    }
    return false;
  };
  int l = 2, r = n, ans = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  std::cout << ans << '\n';
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
