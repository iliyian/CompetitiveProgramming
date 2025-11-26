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
 * @File    : E_Fortress_Fall.cpp
 * @Time    : 2025-10-28 13:37:53
 * @Comment : 分类讨论都是屎题
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  if (x <= 0 && y <= 0) {
    x = -x, y = -y;
    for (auto &i : a) i = -i;
  }
  if (x >= 0 && y >= 0) {
    if (x < y) std::swap(x, y);
    auto b = std::ranges::count_if(a, [&](int x) {return x >= 0;});
    std::ranges::sort(a | std::views::reverse);
    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i += 2) {
      ans = std::max(ans, pre[i / 2] * x + (pre[i] - pre[i / 2]) * y);
    }
    std::cout << ans << '\n';
  } else {
    if (x < y) std::swap(x, y);
    std::ranges::sort(a, std::greater<>());
    int ans = 0;
    for (int i = 0; i < n - i - 1; i++) {
      ans += std::max(0ll, a[i] * x + a[n - i - 1] * y);
    }
    std::cout << ans << '\n';
  }
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
