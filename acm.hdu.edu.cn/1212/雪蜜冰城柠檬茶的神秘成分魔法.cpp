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
 * @File    : 雪蜜冰城柠檬茶的神秘成分魔法.cpp
 * @Time    : 2026-03-13 19:32:27
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::array<int, 3>> ops;
  std::vector<int> v = {LLONG_MIN / 3};
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    ops.push_back({2, x});
    v.push_back(x);
  }
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x >> y;
      v.push_back(x);
      v.push_back(y);
      ops.push_back({op, x, y});
    } else {
      int x;
      std::cin >> x;
      ops.push_back({op, x});
      v.push_back(x);
    }
  }
  // std::sort(v.begin(), v.end());
  // v.erase(std::unique(v.begin(), v.end()), v.end());
  // auto id = [&](int x) {return std::lower_bound(v.begin(), v.end(), x) - v.begin();};
  std::vector<int> ans;
  std::reverse(ops.begin(), ops.end());
  std::map<int, int> mp;
  for (auto [op, x, y] : ops) {
    if (op == 1) {
      if (!mp.count(y)) {
        mp[y] = y;
      }
      mp[x] = mp[y];
    } else if (op == 2) {
      if (!mp.count(x)) {
        mp[x] = x;
      }
      ans.push_back(mp[x]);
    } else {
      mp[x] = 0;
    }
  }
  std::reverse(ans.begin(), ans.end());
  for (auto v : ans) {
    if (v == 0) continue;
    std::cout << v << ' ';
  }
  std::cout << '\n';
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
