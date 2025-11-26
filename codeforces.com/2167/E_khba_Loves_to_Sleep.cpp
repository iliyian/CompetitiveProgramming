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
 * @File    : E_khba_Loves_to_Sleep.cpp
 * @Time    : 2025-10-29 17:51:03
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, x;
  std::cin >> n >> k >> x;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  std::ranges::sort(a);
  auto check = [&](int mid) {
    int now = std::max(0ll, a[0] + 1 - mid) + std::max(0ll, x - a[n - 1] + 1 - mid);
    for (int i = 0; i < n - 1; i++) {
      now += std::max(0ll, a[i + 1] - a[i] - mid * 2 + 1);
    }
    return now >= k;
  };
  int l = 1, r = x, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  // std::cerr << ans << '\n';
  if (ans == 0) {
    for (int i = 0; i < k; i++) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    return;
  }
  for (int i = 0; i <= a[0] - ans && k; i++, k--) {
    std::cout << i << ' ';
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < (a[i + 1] - a[i] - ans * 2 + 1) && k; j++, k--) {
      std::cout << a[i] + ans + j << ' ';
    }
  }
  for (int i = a[n - 1] + ans; i <= x && k; i++, k--) {
    std::cout << i << ' ';
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
