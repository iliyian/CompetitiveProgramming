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
 * @File    : I.cpp
 * @Time    : 2026-02-23 12:18:55
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

// constexpr int mod = 998244353;
std::mt19937_64 rd(std::random_device{}());
using u64 = unsigned long long;

void solve() {
  int n, m1, m2;
  std::cin >> n >> m1 >> m2;
  std::vector<u64> val(n + 1);
  for (int i = 1; i <= n; i++) {
    val[i] = rd();
  }
  auto work = [&](std::vector<std::array<int, 3>> &edges) -> u64 {
    std::vector<int> pa(n + 1), siz(n + 1, 1);
    std::ranges::iota(pa, 0);
    auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
    auto sum = val;
    u64 ans = 0;
    for (auto [w, x, y] : edges) {
      x = find(find, x), y = find(find, y);
      if (x == y) continue;

      if (siz[x] > siz[y]) std::swap(x, y);
      ans += sum[x] * sum[y] * u64(w);

      siz[y] += siz[x];
      sum[y] += sum[x];
      pa[x] = y;
    }
    return ans;
  };
  std::vector<std::array<int, 3>> e1, e2;
  for (int i = 1; i <= m1; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    e1.push_back({w, x, y});
  }
  for (int i = 1; i <= m2; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    e2.push_back({w, x, y});
  }
  std::ranges::sort(e1);
  std::ranges::sort(e2);
  std::cout << (work(e1) == work(e2) ? "YES" : "NO") << '\n';
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
