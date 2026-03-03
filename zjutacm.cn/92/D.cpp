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
 * @File    : D.cpp
 * @Time    : 2025-12-21 14:18:01
 * @Comment : 
 * ==============================================================================
*/

#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n);
  int log = std::__lg(n);
  std::vector<std::vector<std::vector<int>>> st(2, std::vector<std::vector<int>>(log + 1, std::vector<int>(n)));
  std::vector<int> px, py;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    st[0][0][i] = st[1][0][i] = a[i];
    if (a[i] == x) {
      px.push_back(i);
    }
    if (a[i] == y) {
      py.push_back(i);
    }
  }
  for (int i = 0; i < log; i++) {
    for (int j = 0; j + (1 << i) < n; j++) {
      st[0][i + 1][j] = std::min(st[0][i][j], st[0][i][j + (1 << i)]);
      st[1][i + 1][j] = std::max(st[1][i][j], st[1][i][j + (1 << i)]);
    }
  }
  auto get = [&](int l, int r, int idx, auto op) {
    int log = std::__lg(r - l + 1);
    return op(st[idx][log][l], st[idx][log][r - (1 << log) + 1]);
  };
  px.push_back(n);
  py.push_back(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto ansl = std::max(*std::lower_bound(px.begin(), px.end(), i), *std::lower_bound(py.begin(), py.end(), i));
    if (ansl == n) continue;
    int l = ansl, r = n - 1, ansr = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int mn = get(i, mid, 0, [&](auto x, auto y) {return std::min(x, y);});
      int mx = get(i, mid, 1, [&](auto x, auto y) {return std::max(x, y);});
      if (mn == y && mx == x) {
        l = mid + 1, ansr = mid;
      } else {
        r = mid - 1;
      }
    }
    // std::cerr << i << ' ' << ansl << ' ' << ansr << '\n';
    if (ansr != -1) {
      ans += ansr - ansl + 1;
    }
  }
  std::cout << ans << '\n';
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
