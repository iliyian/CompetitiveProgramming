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
 * @File   : E_ace_5_and_Task_Order.cpp
 * @Time   : 2025-10-24 11:54:39
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

int ask(int x) {
  std::cout << "? " << x << std::endl;
  char ans;
  std::cin >> ans;
  if (ans == '>') return 1;
  else if (ans == '<') return -1;
  return 0;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> ans(n + 1);
  auto work = [&](this auto &&self, std::vector<int> v, int pre) -> void {
    if (v.empty()) return;
    if (v.size() == 1) {
      ans[v[0]] = pre;
      return;
    }
    int p = rd() % v.size();
    while (ask(v[p]));
    std::vector<int> l, r;
    for (int i = 0; i < v.size(); i++) {
      if (i != p) {
        int ans = ask(v[i]);
        if (ans == 1) r.push_back(v[i]);
        else if (ans == -1) l.push_back(v[i]);
        else assert(false);
        ask(v[p]);
      }
    }
    ans[v[p]] = pre + l.size();
    self(l, pre);
    self(r, pre + l.size() + 1);
  };
  std::vector<int> v(n);
  std::ranges::iota(v, 1);
  work(v, 1);
  std::cout << "! ";
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << std::endl;
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