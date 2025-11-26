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
 * @File    : D_Copy_String.cpp
 * @Time    : 2025-11-06 23:22:41
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string s, t;
  std::cin >> s >> t;
  std::vector<std::vector<int>> to(n);
  std::vector<int> lc(n, -1);
  int l = -1, mxk = 0;
  // std::set<int> st;
  std::vector<int> st;
  std::vector<std::vector<int>> pos(128);
  for (int i = 0; i < n; i++) {
    pos[s[i]].push_back(i);
  }
  int r = n;
  for (int i = n - 1; i >= 0; i--) {
    r = std::min(r, i);
    auto q = std::ranges::upper_bound(pos[t[i]], r) - pos[t[i]].begin() - 1;
    if (q == -1) {
      std::cout << -1 << '\n';
      return;
    }
    lc[i] = pos[t[i]][q];
    r = std::min({r, lc[i]});
    if (lc[i] != i) {
      // st.insert(i);
      st.push_back(i);
    }
    mxk = std::max(mxk, i - lc[i]);
  }
  if (mxk > k) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << mxk << '\n';
  // for (int i = 0; i < n; i++) {
  //   std::cerr << lc[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (auto i : st) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  // std::set<int> nxt;
  std::vector<int> nxt;
  std::string ans(n, '0');
  while (!st.empty()) {
    int j = n - 1;
    for (auto i : st) {
      while (j >= lc[i] + 1) {
        if (j == lc[i] + 1) {
          // ans.push_back(s[lc[i]]);
          ans[j] = s[lc[i]];
        } else {
          // ans.push_back(s[j]);
          ans[j] = s[j];
        }
        j--;
      }
      lc[i]++;
      if (lc[i] != i) {
        // nxt.insert(i);
        nxt.push_back(i);
      }
    }
    while (j >= 0) {
      // ans.push_back(t[j--]);
      ans[j] = t[j];
      j--;
    }
    std::cout << ans << '\n';
    s = ans; // n * k ?
    st = std::move(nxt); // n * k ? 
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
