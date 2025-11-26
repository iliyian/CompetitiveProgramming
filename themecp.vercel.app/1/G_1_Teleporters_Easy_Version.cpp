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
 * @File    : G_2_Teleporters_Hard_Version.cpp
 * @Time    : 2025-11-13 20:19:30
 * @Comment : 各种地方都疼，头疼，不知道布洛芬效果......反正已经吃了挺多了好像......好难受......好难受......好难受......好难受......
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n), pre(n + 1), p(n);
  std::ranges::iota(p, 0);
  for (auto &i : a) std::cin >> i;
  auto val = [&](int x) {
    return x + 1 + a[x];
  };
  std::ranges::sort(p, [&](auto x, auto y) {
    return val(x) < val(y);
  });
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + val(p[i]);
  }
  auto get = [&](int now, int x) {
    if (now >= x) {
      return pre[x - 1] + val(p[now]);
    } else {
      return pre[x];
    }
  };
  for (int i = 0; i < n; i++) {
    std::cerr << pre[i + 1] << ' ';
  }
  std::cerr << '\n';
  int res = 0;
  for (int i = 0; i < n; i++) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      // std::cerr << i << ' ' << mid << ' ' << get(i, mid) << '\n';
      if (get(i, mid) <= c) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    // std::cerr << i << ' ' << ans << '\n';
    res = std::max(res, ans);
  }
  std::cout << res << '\n';
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
