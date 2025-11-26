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
 * @File    : E_Permutation_Sorting.cpp
 * @Time    : 2025-11-01 16:56:01
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), h(n + 1);
  std::vector<std::vector<int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    h[i] = (a[i] >= i ? a[i] - i : n - i + a[i]);
    v[h[i]].push_back(i);
  }
  std::vector<int> d(n * 2 + 1);
  auto add = [&](int x, int c) {for (int i = x; i <= n * 2; i += i & -i) d[i] += c;};
  auto query = [&](int x) {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;};
  auto get = [&](int l, int r) {
    if (r < l) return 0ll;
    return query(r) - query(l - 1);
  };
  std::vector<int> ans(n + 1);
  for (int i = 0; i <= n; i++) {
    for (int j : v[i]) {
      ans[a[j]] = get(j + 1, j + h[j] - 1);
    }
    for (int j : v[i]) {
      if (a[j] <= j) {
        add(j, 1);
      }
      if (a[j] >= j) {
        add(j + n, 1);
      }
    }
    for (int j = 1; j <= n * 2; j++) {
      std::cerr << query(j) - (j > 1 ? query(j - 1) : 0) << ' ';
    }
    std::cerr << '\n';
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
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
