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
 * @File    : A_Savior.cpp
 * @Time    : 2025-11-26 09:51:15
 * @Comment : 只能说有点adhoc，古早题目是这样的，完全就是考生成......
 * ==============================================================================
*/

#include <bits/stdc++.h>
// #define int long long

void solve() {
  int n;
  std::cin >> n;
  int mx = 0;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i, mx = std::max(mx, i);
  mx *= 2;
  std::vector<bool> vis(mx + 1);
  for (auto &i : a) {
    vis[i] = 1;
  }
  std::set<std::array<int, 3>> s;
  std::vector<int> pa(mx + 1), siz(mx + 1, 1);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  auto check = [&](int x, int y) {
    if (vis[x] && vis[y]) {
      merge(x, y);
    }
  };
  std::ranges::iota(pa, 0);
  for (int x = 1; x * x <= mx; x++) {
    for (int y = x + 1; y * y + x * x <= mx; y++) {
      int a = y * y - x * x, b = 2 * x * y, c = x * x + y * y;
      int g = std::gcd(std::gcd(a, b), c);
      if (g == 1) {
        check(a, b);
        check(a, c);
        check(b, c);
        if (a > b) std::swap(a, b);
        // s.insert({a, b, c});
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= mx; i++) {
    if (vis[i] && pa[i] == i) {
      ans++;
    }
  }
  std::cout << ans << "\n";
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
