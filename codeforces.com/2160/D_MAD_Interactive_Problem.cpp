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
 * @Author : iliyian
 * @File   : D_MAD_Interactive_Problem.cpp
 * @Time   : 2025-10-16 19:44:26
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int ask(std::vector<int> v) {
  std::ranges::sort(v);
  std::cout << "? " << v.size() << ' ';
  for (auto i : v) {
    std::cout << i + 1 << ' ';
  }
  std::cout << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(std::vector<int> v) {
  std::cout << "! ";
  for (auto i : v) {
    std::cout << i + 1 << ' ';
  }
  std::cout << std::endl;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> no;
  no.push_back(0);
  std::vector<int> ans(n * 2, -1);
  for (int i = 1; i < n * 2; i++) {
    no.push_back(i);
    int s = ask(no);
    s--;
    if (s != -1) {
      ans[i] = s;
      no.pop_back();
    }
  }
  no.clear();
  for (int i = 0; i < n * 2; i++) {
    if (ans[i] != -1) {
      no.push_back(i);
    }
  }
  for (int i = 0; i < n * 2; i++) {
    if (ans[i] == -1) {
      no.push_back(i);
      ans[i] = ask(no) - 1;
      no.pop_back();
    }
  }
  answer(ans);
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
