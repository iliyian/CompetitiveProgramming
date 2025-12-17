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
 * @File    : F_Disjoint_Triangles.cpp
 * @Time    : 2025-12-10 18:04:18
 * @Comment : 真他妈的妙
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

using std::numbers::pi;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    std::cin >> x >> y;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    std::vector<long double> b;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        b.push_back(atan2l(a[j].second - a[i].second, a[j].first - a[i].first));
      }
    }
    std::ranges::sort(b);
    // for (auto i : b) {
    //   std::cerr << i / pi * 180 << ' ';
    // }
    // std::cerr << '\n';
    for (int j = 0; j < n - 1; j++) {
      long double deg = b[j];
      int l = 0, r = n - 2, k = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        long double d = b[(mid + j) % (n - 1)] - deg;
        if (d < 0) d += pi * 2;
        if (d < pi) l = mid + 1, k = mid;
        else r = mid - 1;
      }
      int kk = n - 2 - k;
      ans += k * (k - 1) / 2 * kk * (kk - 1) / 2;
    }
  }
  std::cout << ans / 2 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
