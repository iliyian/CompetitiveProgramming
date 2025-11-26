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
 * @File    : B_CoCo_Count.cpp
 * @Time    : 2025-10-28 13:35:28
 * @Comment : 还是很有趣和很典的一道题吧？
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  std::vector<int> v;
  for (auto &i : a) std::cin >> i, v.push_back(i);
  for (auto &i : b) std::cin >> i, v.push_back(i);
  std::ranges::sort(v);
  for (auto &i : a) i = std::ranges::lower_bound(v, i) - v.begin();
  for (auto &i : b) i = std::ranges::lower_bound(v, i) - v.begin();
  std::vector<int> pos(n * 2, n), closest_b_for_a(n);
  std::vector<std::vector<int>> left_a_for_b(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    pos[b[i]] = i;
    left_a_for_b[pos[a[i]]].push_back(i);
  }
  std::ranges::fill(pos, -1);
  // 错的这么离谱竟然能过样例
  for (int i = 0; i < n; i++) {
    pos[b[i]] = i;
    closest_b_for_a[i] = pos[a[i]];
  }
  int ans = 0;
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) -> void {for (int i = x + 1; i <= n; i += i & -i) d[i] += c;};
  auto query = [&](int x) -> int {if(x < 0) return 0; int ans = 0; for (int i = x + 1; i > 0; i -= i & -i) ans += d[i]; return ans;};
  int tot = 0;
  for (int i = 0; i < n; i++) {
    for (auto j : left_a_for_b[i]) {
      add(j, 1);
      tot++;
    }
    ans += tot - query(closest_b_for_a[i]);
    // std::cerr << ans << ' ' << tot << '\n';
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
