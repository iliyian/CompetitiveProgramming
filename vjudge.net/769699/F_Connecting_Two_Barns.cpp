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
 * @File    : F_Connecting_Two_Barns.cpp
 * @Time    : 2025-12-02 18:34:51
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  auto find = [&](auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    siz[y] += siz[x];
    pa[x] = y;
    return true;
  };
  std::iota(pa.begin(), pa.end(), 0);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    merge(x, y);
  }
  if (find(find, 1) == find(find, n)) {
    std::cout << 0 << '\n';
    return;
  }
  std::vector<int> v1, vn, v;
  for (int i = 1; i <= n; i++) {
    if (find(find, i) == find(find, 1)) {
      v1.push_back(i);
    } else if (find(find, i) == find(find, n)) {
      vn.push_back(i);
    } else {
      v.push_back(i);
    }
  }
  auto get_closest = [&](int x, std::vector<int> &v) {
    int ans = LLONG_MAX / 3;
    auto p = std::lower_bound(v.begin(), v.end(), x);
    if (p != v.end()) {
      ans = std::min(ans, (*p - x) * (*p - x));
    }
    if (p != v.begin()) {
      p--;
      ans = std::min(ans, (*p - x) * (*p - x));
    }
    return ans;
  };
  int ans = LLONG_MAX / 3;
  for (int i : v1) {
    ans = std::min(ans, get_closest(i, vn));
  }
  std::vector<int> l(n + 1, LLONG_MAX / 3), r(n + 1, LLONG_MAX / 3);
  for (int i : v) {
    int p = find(find, i);
    l[p] = std::min(l[p], get_closest(i, v1));
    r[p] = std::min(r[p], get_closest(i, vn));
    ans = std::min(ans, l[p] + r[p]);
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
