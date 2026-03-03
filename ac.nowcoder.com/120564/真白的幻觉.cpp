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
 * @File    : 真白的幻觉.cpp
 * @Time    : 2026-02-09 16:00:55
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::map<int, int> mem;

int f(int x) {
  if (x == 0) return 0;
  int ans = 1;
  while (x) {
    ans = ans * (x % 10);
    x /= 10;
  }
  return ans;
}

int g(int x) {
  for (int i = 0;; i++) {
    int y = f(x);
    if (y == x) return i;
    x = y;
  }
}

void solve() {
  std::map<int, std::vector<int>> mp;
  for (int x = 0; x <= 10000000; x++) {
    mp[g(x)].push_back(x);
    // std::cout << x << ' ' << g(x) << '\n';
  }
  for (auto &[k, v] : mp) {
    for (auto v : v) {
      std::cout << v << ' ';
    }
    std::cout << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

//   // freopen("ans.txt", "w", stdout);
// 
  int prod[] = {0, 2, 3, 5, 7};
//   int lim = 1000000000000000000ll;
//   // std::map<int, int> mp;
//   std::map<int, std::vector<int>> mp;
//   auto dfs = [&](auto self, int u, int dep) {
//     if (dep == 5) {
//       // if (mp.count(g(u))) return;
//       mp[g(u)].push_back(u);
//       // std::cout << u << ' ' << f(u) << '\n';
//       return;
//     }
//     for (int i = 0; i < 70; i++) {
//       self(self, u, dep + 1);
//       u *= prod[dep];
//       if (u > lim) break;
//     }
//   };
//   dfs(dfs, 1, 1);
//   for (auto [k, v] : mp) {
//     for (auto v : v) {
//       std::cout << k << ' ' << v << '\n';
//     }
//   }

  int x = 4996238671872, y = 937638166841712;
  auto sol = [&](int x) {
    int cnt[5] {};
    for (int i = 1; i <= 4; i++) {
      while (x % prod[i] == 0) x /= prod[i], cnt[i]++;
      // cnt[i]++;
    }
    for (int i = 1; i <= 4; i++) {
      std::cout << cnt[i] << ' ';
    }
    std::cout << '\n';
  };
  // sol(x), sol(y);
  std::cout << "997777778888882" << ' ' << "77777999999999982" << '\n';
  // std::cout << f(997777778888882) << ' ' << g(997777778888882) << '\n';
  // std::cout << f(77777999999999982) << ' ' << g(77777999999999982) << '\n';
  // std::cout << sol(x) << ' ' << sol(y) << '\n';


  // std::cout << 937638166841712 << ' ' << 4996238671872 << '\n';
  // std::cout << f(4996238671872) << ' ' << f(937638166841712) << '\n';
  // std::cout << g(4996238671872) << ' ' << g(937638166841712) << '\n';

  return 0;

  int t = 1;
  // std::cin >> t;

  while (t--) {
    // solve();
  }

  return 0;
}
