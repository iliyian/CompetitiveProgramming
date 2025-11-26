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
 * @File    : F_Repetitions_Decoding.cpp
 * @Time    : 2025-11-25 19:24:39
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  for (auto [k, v] : cnt) {
    if (v % 2 == 1) {
      std::cout << -1 << '\n';
      return;
    }
  }
  std::vector<std::pair<int, int>> ans;
  std::vector<int> ans2;
  auto op = [&](int x, int c) {
    a.insert(a.begin() + x, c);
    a.insert(a.begin() + x, c);
    n += 2;
    ans.push_back({x - 1, c});
  };
  int pre = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[j] == a[i]) {
        int len = j - i - 1;
        for (int k = i + 1; k < j; k++) {
          op(k - i + j, a[k]);
        }
        ans2.push_back(len + 1);
        i = j + len;
        break;
      }
    }
  }
  std::cout << ans.size() << '\n';
  for (auto [x, c] : ans) {
    std::cout << x << ' ' << c << '\n';
  }
  std::cout << ans2.size() << '\n';
  for (auto i : ans2) {
    std::cout << i * 2 << ' ';
  }
  std::cout << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << a[i] << ' ';
  // }
  // std::cerr << '\n';
  // std::cout << '\n';
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
