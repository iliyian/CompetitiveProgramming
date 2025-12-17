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
 * @File    : C_Mooyo_Mooyo.cpp
 * @Time    : 2025-12-02 19:17:57
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::string> s(n);
  for (auto &str : s) std::cin >> str;
  auto work = [&]() {
    std::vector<int> pa(n * 10), siz(n * 10, 1);
    auto find = [&](auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
    auto f = [&](int x) {return find(find, x);};
    auto merge = [&](int x, int y) {
      x = find(find, x), y = find(find, y);
      if (x == y) return false;
      if (siz[x] > siz[y]) std::swap(x, y);
      siz[y] += siz[x];
      siz[x] = 0;
      pa[x] = y;
      return true;
    };
    std::iota(pa.begin(), pa.end(), 0);
    auto id = [&](int i, int j) {
      return i * 10 + j;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 10; j++) {
        int x = id(i, j), y = id(i, j + 1), z = id(i + 1, j);
        if (j + 1 < 10 && s[i][j] == s[i][j + 1]) {
          merge(x, y);
        }
        if (i + 1 < n && s[i][j] == s[i + 1][j]) {
          merge(x, z);
        }
      }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 10; j++) {
        int p = f(id(i, j));
        if (s[i][j] != '0' && siz[p] >= k) {
          s[i][j] = '0';
          flag = true;
        }
      }
    }
    if (!flag) {
      return false;
    }
    // for (auto &str : s) {
    //   std::cerr << str << '\n';
    // }
    // std::cerr << '\n';
    std::vector<std::string> t(n, std::string(10, '0'));
    for (int j = 0; j < 10; j++) {
      int h = 0;
      for (int i = n - 1; i >= 0; i--) {
        if (s[i][j] == '0') {
          h++;
        } else {
          t[i + h][j] = s[i][j];
        }
      }
    }
    s = std::move(t);
    // for (auto &str : s) {
    //   std::cerr << str << '\n';
    // }
    // std::cerr << '\n';
    return true;
  };
  while (work());
  for (auto &str : s) {
    std::cout << str << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("mooyomooyo.in", "r", stdin);
  freopen("mooyomooyo.out", "w", stdout);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
