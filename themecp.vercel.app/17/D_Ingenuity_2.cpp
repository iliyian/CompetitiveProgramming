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
 * @File    : D_Ingenuity_2.cpp
 * @Time    : 2025-12-10 18:27:31
 * @Comment : #65：如果真的都尽力了，真的排除一切可能了，我们真的只能放弃了吗？我们真的没有这份天赋吗？还是少了什么？
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<int> N, S, E, W;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N') N.push_back(i);
    if (s[i] == 'S') S.push_back(i);
    if (s[i] == 'E') E.push_back(i);
    if (s[i] == 'W') W.push_back(i);
  }
  std::string ans(n, '$');
  if (std::abs((int)N.size() - (int)S.size()) % 2) {
    std::cout << "NO\n";
    return;
  }
  if (std::abs((int)E.size() - (int)W.size()) % 2) {
    std::cout << "NO\n";
    return;
  }
  auto work = [&](std::vector<int> &N, std::vector<int> &S, int t) {
    for (int i = 0; i < std::min(N.size(), S.size()); i++) {
      ans[N[i]] = i % 2 == t ? 'R' : 'H';
      ans[S[i]] = i % 2 == t ? 'R' : 'H';
    }
    if (N.size() < S.size()) N.swap(S);
    for (int i = S.size(); i < N.size(); i += 2) {
      ans[N[i]] = 'R';
      ans[N[i + 1]] = 'H';
    }
  };
  work(N, S, 1);
  work(E, W, 0);
  if (!std::ranges::count(ans, 'H') || !std::ranges::count(ans, 'R')) {
    std::cout << "NO\n";
    return;
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
