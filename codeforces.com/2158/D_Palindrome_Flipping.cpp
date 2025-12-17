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
 * @File    : D_Palindrome_Flipping.cpp
 * @Time    : 2025-11-29 23:13:34
 * @Comment : 还是可以写的很优雅的？
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<std::vector<std::pair<int, int>>> mp(16);

void solve() {
  int n;
  std::cin >> n;
  std::string s, t;
  std::cin >> s >> t;
  s = '#' + s;
  t = '#' + t;
  auto to_zero = [&](std::string &s) {
    std::vector<std::pair<int, int>> ans;
    int v = 0;
    for (int i = 1; i <= 4; i++) {
      v = v * 2 + s[i] - '0';
    }
    auto op = [&](int l, int r) {
      ans.push_back({l, r});
      for (int i = l; i <= r; i++) {
        s[i] ^= 1;
      }
    };  
    for (auto [l, r] : mp[v] | std::views::reverse) {
      op(l, r);
    }
    for (int i = 5; i <= n; i++) {
      if (s[i] != s[i - 1]) {
        op(1, i - 1);
      }
    }
    if (s.back() == '1') {
      op(1, n);
    }
    return ans;
  };
  auto anss = to_zero(s), anst = to_zero(t);

  std::cout << anss.size() + anst.size() << '\n';
  for (auto [l, r] : anss) {
    std::cout << l << ' ' << r << '\n';
  }
  for (auto [l, r] : anst | std::views::reverse) {
    std::cout << l << ' ' << r << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int l = 0; l < 4; l++) {
      for (int r = l + 1; r < 4; r++) {
        bool flag = true;
        for (int i = l; i <= r; i++) {
          if ((u >> i & 1) != (u >> (r - (i - l)) & 1)) {
            flag = false;
            break;
          }
        }
        if (flag) {
          int v = u;
          for (int i = l; i <= r; i++) {
            v ^= 1 << i;
          }
          if (mp[v].empty() && v) {
            mp[v] = mp[u];
            mp[v].push_back({4 - r, 4 - l});
            q.push(v);
          }
        }
      }
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
