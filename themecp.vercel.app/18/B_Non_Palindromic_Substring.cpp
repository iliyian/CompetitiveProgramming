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
 * @File    : B_Non_Palindromic_Substring.cpp
 * @Time    : 2025-12-26 19:38:52
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int getprime(int x) {
  while (!isprime(x)) x++;
  return x;
}

std::mt19937_64 rd(std::random_device{}());

const int P = getprime(rd() % (int)9e8 + 1e8);

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;
  s = '#' + s;
  std::vector<std::array<int, 26>> cnt(n + 1), cnt1(n + 1), cnt0(n + 1);
  cnt1[1][s[1] - 'a'] = 1;
  cnt[1][s[1] - 'a'] = 1;
  for (int i = 2; i <= n; i++) {
    if (i % 2) {
      cnt1[i] = cnt1[i - 2];
      cnt1[i][s[i] - 'a']++;
    } else {
      cnt0[i] = cnt0[i - 2];
      cnt0[i][s[i] - 'a']++;
    }
    cnt[i] = cnt[i - 1];
    cnt[i][s[i] - 'a']++;
  }
  auto all_same = [&](int l, int r) {
    int c = s[r] - 'a';
    if (cnt[r][c] - cnt[l - 1][c] == r - l + 1) {
      return true;
    }
    return false;
  };
  auto jiaocuo = [&](int l, int r) {
    if (r - l == 1) return !all_same(l, r);
    int _l[2] {}, _r[2] {};
    _l[l & 1] = l, _r[r & 1] = r;
    _l[l & 1 ^ 1] = l + 1, _r[r & 1 ^ 1] = r - 1;
    for (int i = 0; i < 2; i++) {
      int c = s[_r[i]] - 'a';
      auto &cnt = i ? cnt1 : cnt0;
      if (cnt[_r[i]][c] - (_l[i] > 1 ? cnt[_l[i] - 2][c] : 0) == (_r[i] - _l[i]) / 2 + 1) {
      } else {
        return false;
      }
    }
    return true;
  };
  std::vector<int> h(n + 1), rh(n + 2), p(n + 1);
  int base = 233;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * base % P;
    h[i] = h[i - 1] * base % P + s[i] - 'a';
    h[i] %= P;
    rh[i] = rh[i - 1] * base + s[n - i + 1] - 'a';
    rh[i] %= P;
  }
  auto get = [&](int l, int r, std::vector<int> &h) {
    return (h[r] - h[l - 1] * p[r - l + 1] % P + P) % P;
  };
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (all_same(l, r)) {
      std::cout << 0 << '\n';
      continue;
    }
    int len = (r - l + 1);
    if (jiaocuo(l, r)) {
      if (len % 2) len--;
      std::cout << (1 + len / 2) * len / 2 << '\n';
      continue;
    }
    int ans = (2 + len) * (len - 1) / 2;
    if (get(l, r, h) == get(n - r + 1, n - l + 1, rh)) {
      ans -= len;
    }
    std::cout << ans << '\n';
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
