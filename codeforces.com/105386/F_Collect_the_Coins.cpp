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
 * @File    : F_Collect_the_Coins.cpp
 * @Time    : 2025-11-07 18:29:26
 * @Comment : 妙妙题！我们每时刻都只指定任意一只机器人吃当前，维护任意的另一只的范围区间......
    区间重合则意味着，至少在这一步，两者是真的完全可以互相代替了
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int inf = LLONG_MAX / 3;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> t(n), d(n);
  for (int i = 0; i < n; i++) {
    std::cin >> t[i] >> d[i];
  }
  auto check = [&](int mid) -> bool {
    int l = -inf, r = inf;
    for (int i = 1; i < n; i++) {
      int w = (t[i] - t[i - 1]) * mid;
      int nl = inf, nr = -inf;
      if (std::abs(d[i] - d[i - 1]) <= w) {
        int ll = l - w, rr = r + w;
        nl = std::min(nl, ll);
        nr = std::max(nr, rr);
      }
      if (l - w <= d[i] && d[i] <= r + w) {
        int ll = d[i - 1] - w, rr = d[i - 1] + w;
        nl = std::min(nl, ll);
        nr = std::max(nr, rr);
      }
      nl = std::max(nl, -inf);
      nr = std::min(nr, inf);
      l = nl, r = nr;
      if (l > r) {
        return false;
      }
    }
    return true;
  };
  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
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
