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
 * @File    : 二分图判定.cpp
 * @Time    : 2025-12-07 13:01:20
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  // n = rd() % 20 + 1;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    // a[i] = rd() % 200 + 1;
  }
  std::sort(a.begin() + 1, a.end());

  auto check = [&](int mid) -> bool {
    for (int i = 2; i <= n - 1; i++) {
      if (a[i] - a[1] > mid && a[n] - a[i] > mid) {
        return false;
      }
    }
    return true;
  };
  int l = 0, r = 2e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }

  std::cout << ans << '\n';
  // std::vector<int> col(n + 1);
  // bool flag = true;
  // auto dfs = [&](this auto &&self, int u) -> void {
  //   for (int i = 1; i <= n; i++) {
  //     if (i != u) {
  //       if (!flag) return;
  //       if (std::abs(a[u] - a[i]) <= ans) continue;
  //       if (col[i] && col[i] != 3 - col[u]) {
  //         flag = false;
  //         std::cout << "GG\n";
  //         std::cerr << n << '\n';
  //         for (int i = 1; i <= n; i++) {
  //           std::cerr << a[i] << ' ';
  //         }
  //         std::cerr << '\n';
  //         return;
  //       }
  //       if (col[i]) continue;
  //       col[i] = 3 - col[u];
  //       self(i);
  //     }
  //   }
  // };
  // for (int i = 1; i <= n; i++) {
  //   if (!col[i]) {
  //     if (!flag) break;
  //     col[i] = 1;
  //     dfs(i);
  //   }
  // }
  // std::cout << "OK\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;
  // t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
