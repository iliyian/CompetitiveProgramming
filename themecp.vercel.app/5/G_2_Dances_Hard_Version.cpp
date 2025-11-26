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
 * @File    : G_2_Dances_Hard_Version.cpp
 * @Time    : 2025-11-21 20:52:51
 * @Comment : 这类题目还是应该先贪心的判断总体趋势，从总体趋势入手......然后开始枚举？
              顺带一提两个log还跑得挺快
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n - 1), b(n);
  for (auto &i : a) std::cin >> i;
  for (auto &i : b) std::cin >> i;
  std::ranges::sort(b);
  auto work = [&](int mid) -> int {
    auto aa = a;
    aa.push_back(mid);
    std::ranges::sort(aa);
    int ans = 0, p = 0, nn = n;
    for (int i = 0; i < nn; i++) {
      auto q = std::upper_bound(b.begin() + p, b.end(), aa[i]) - b.begin();
      ans += q - p;
      nn -= q - p;
      p = q + 1;
    }
    return ans;
  };
  int ansl = work(1), ansr = work(m);
  int l = 1, r = m, cnt = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (work(mid) == ansl) l = mid + 1, cnt = mid;
    else r = mid - 1;
  }
  // std::cerr << ansl << ' ' << ansr << ' ' << cnt << '\n';
  std::cout << cnt * ansl + (m - cnt) * ansr << '\n';
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
