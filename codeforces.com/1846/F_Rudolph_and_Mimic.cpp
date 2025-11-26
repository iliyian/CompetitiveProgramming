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
 * @File   : F_Rudolph_and_Mimic.cpp
 * @Time   : 2025-10-08 18:34:12
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::cout << "- 0" << std::endl;
  int cnt1[10] {}, cnt2[10] {};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt1[a[i]]++;
  }
  std::cout << "- 0" << std::endl;
  std::vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    cnt2[b[i]]++;
  }
  int target = 0;
  for (int i = 1; i <= 9; i++) {
    if (cnt2[i] > cnt1[i]) {
      target = i;
      break;
    }
  }
  std::vector<int> del;
  for (int i = 1; i <= n; i++) {
    if (b[i] != target) {
      del.push_back(i);
    }
  }
  std::cout << "- " << del.size() << ' ';
  for (auto i : del) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::cout << "- 0" << std::endl;
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::cout << "- 0" << std::endl;
  
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
