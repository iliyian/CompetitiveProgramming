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
 * @File    : K.cpp
 * @Time    : 2025-11-04 19:39:49
 * @Comment : 爽！这题不知道卡几个月还是几个星期了，原来是1的时候的merge部分写错了，没考虑嵌套的情况
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> ans(n + 1);
  auto solve = [&](this auto &&self, int l, int r, std::vector<int> now) {
    if (l > r || now.empty()) return;
    if (l == r) {
      ans[l] = now.front();
      return;
    }
    int mid = (l + r) / 2;
    std::vector<int> lv, rv;
    std::vector<std::vector<int>> has(n + 1);
    for (int i : now) {
      has[i].push_back(i);
    }
    auto push = [&](int x, std::vector<int> &v) {
      for (int i : has[x]) {
        v.push_back(i);
      }
    };
    while (now.size() >= 2) {
      std::shuffle(now.begin(), now.end(), rd);
      std::cout << 0 << ' ';
      int len = now.size();
      for (int i = 1; i <= n; i++) {
        std::cout << (i <= mid ? now[len - 2] : now[len - 1]) << ' ';
      }
      std::cout << std::endl;
      int ans;
      std::cin >> ans;
      if (ans == 2) {
        push(now[len - 2], lv);
        push(now[len - 1], rv);
        now.pop_back();
        now.pop_back();
      } else if (ans == 1) {
        for (auto i : has[now[len - 1]]) {
          has[now[len - 2]].push_back(i);
        }
        has[now[len - 1]].clear();
        now.pop_back();
      } else {
        push(now[len - 1], lv);
        push(now[len - 2], rv);
        now.pop_back();
        now.pop_back();
      }
    }
    mid = (l + r) / 2;
    if (now.size() == 1) {
      if (lv.size() != mid - l + 1) {
        push(now.front(), lv);
      } else {
        push(now.front(), rv);
      }
    }
    self(l, mid, std::move(lv));
    self(mid + 1, r, std::move(rv));
  };
  std::vector<int> ini(n);
  std::ranges::iota(ini, 1);
  solve(1, n, std::move(ini));
  std::cout << 1 << ' ';
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << std::endl;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}