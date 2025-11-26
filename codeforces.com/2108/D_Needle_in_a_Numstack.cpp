// 这个二分邪门的很

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
 * @File   : D_Needle_in_a_Numstack.cpp
 * @Time   : 2025-10-09 21:30:21
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int ask(int x) {
  std::cout << "? " << x + 1 << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(int x, int y) {
  std::cout << "! " << x << ' ' << y << std::endl;
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(k), b(k);
  for (int i = 0; i < k; i++) {
    a[i] = ask(i);
  }
  for (int i = n - k; i < n; i++) {
    b[i % k] = ask(i);
  }
  std::vector<int> vec;
  int tot = 0;
  for (int i = 0; i < k; i++) {
    if (a[i] != b[i]) {
      vec.push_back(i);
      tot += (n - k * 2) / k;
      if (i < n % k) {
        tot++; // 最后多出来的一点
      }
    }
  }
  std::cerr << "tot=" << tot << '\n';
  for (auto i : vec) {
    std::cerr << i << ' ';
  }
  std::cerr << '\n';
  auto get = [&](int i) -> int {
    if (i == -1) {
      return k - 1;
    }
    if (i == tot) {
      return n - k;
    }
    return i / vec.size() * k + vec[i % vec.size()] + k; // 转换到实际位置
  };
  int lo = -1, hi = tot;
  while (hi - lo > 1) { // 这玩意好像在同时二分两个开区间
    int mid = (lo + hi) / 2;
    int x = get(mid);
    if (ask(x) == a[x % k]) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  lo = get(lo), hi = get(hi);
  if (hi - lo > 1) {
    std::cout << "! " << -1 << std::endl;
  } else {
    std::cout << "! " << lo + 1 << ' ' << n - lo - 1 << std::endl; 
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
