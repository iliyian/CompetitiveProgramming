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
 * @File    : H.cpp
 * @Time    : 2025-11-04 17:34:53
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long


void print(int x) {
  if (x < 2) {
    std::cout << x;
    return;
  }
  print(x / 2);
  std::cout << x % 2;
}

std::vector<int> b = {1073741823,939524095,1,2,3,4,5,6,7};

int getanswer(int x) {
  int ans = 0;
  for (int i : b) {
    ans = std::max(ans, x ^ i);
  }
  return ans;
}

std::map<int, int> mp;
int ask(int x) {
  std::cout << "? ";
  // print(x);
  std::cout << x;
  std::cout << std::endl;
  int ans;
  std::cin >> ans;
  // ans = getanswer(x);
  // print(ans ^ x);
  // std::cout << std::endl;
  return ans ^ x;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> ans;
  auto get1 = [&](int x) {
    return (1ll << x) - 1;
  };
  int totmx = ask(0), totmn = ask(get1(30));
  auto work = [&](this auto &&self, int pre, int pos, int mx, int mn) -> void {
    if (mx == mn) {
      return;
    }
    if (ans.size() == n) {
      return;
    }
    for (int i = pos; i >= 0; i--) {
      if ((mx >> i & 1) ^ (mn >> i & 1)) {
        // print(pre);
        // std::cout << std::endl;
        // if ()
        int nx_mn = ask(pre | get1(i));  // ?0111
        int nx_mx = ask(pre | (1ll << i)); // ?1000
        if (nx_mn != mx) {
          ans.push_back(nx_mn);
        }
        if (nx_mx != mn) {
          ans.push_back(nx_mx);
        }
        self(pre, pos, mx, nx_mn);
        self(pre, pos, nx_mx, mn);
        break;
      } else {
        if (~mx >> i & 1) {
          pre |= 1ll << i;
        }
      }
    }
  };
  ans.push_back(totmx);
  ans.push_back(totmn);
  int pos = 30;
  while (~totmx >> pos & 1) pos--;
  work(0, pos, totmx, totmn);
  // std::cerr << ans.size() << std::endl;
  std::cout << "! ";
  for (auto i : ans) {
    std::cout << i << ' ';
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
