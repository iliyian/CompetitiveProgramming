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
 * @File    : B_Antiamuny_Wants_to_Learn_Swap.cpp
 * @Time    : 2025-11-16 12:07:23
 * @Comment : 又给我roll了个做过的div1,2的题说是
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::stack<int> s;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] > a[i]) {
      r[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] < a[i]) {
      l[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  std::vector<int> mxl(n + 1);
  for (int i = 1; i <= n; i++) {
    if (l[i] && r[i]) {
      mxl[r[i]] = std::max(mxl[r[i]], l[i]);
      // std::cerr << l[i] << ' ' << i << ' ' << r[i] << '\n';
    }
  }
  std::vector<std::vector<std::pair<int, int>>> ask(n + 1);
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    ask[r].push_back({l, i});
  }
  std::vector<int> ans(q + 1);
  int mxL = 0;
  for (int r = 1; r <= n; r++) {
    mxL = std::max(mxL, mxl[r]);
    for (auto [l, idx] : ask[r]) {
      ans[idx] = mxL < l;
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << (ans[i] ? "YES" : "NO") << '\n';
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
