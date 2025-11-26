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
 * @File    : C_Tea_Tasting.cpp
 * @Time    : 2025-11-21 19:17:06
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), pre(n + 1);
  for (auto &i : a) std::cin >> i;
  for (auto &i : b) std::cin >> i;
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + b[i];
  }
  std::vector<int> ans(n + 3), cnt(n + 3);
  for (int i = 0; i < n; i++) {
    int l = i + 1, r = n, _ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (pre[mid] - pre[i] <= a[i]) l = mid + 1, _ans = mid;
      else r = mid - 1;
    }
    if (_ans == -1) {
      ans[i + 1] += a[i];
      ans[i + 2] -= a[i];
    } else {
      cnt[i + 1]++;
      cnt[_ans + 1]--;
      if (pre[_ans] - pre[i] < a[i]) {
        int d = a[i] - (pre[_ans] - pre[i]);
        ans[_ans + 1] += d;
        ans[_ans + 2] -= d;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i + 1] += ans[i];
    cnt[i + 1] += cnt[i];
    std::cout << ans[i + 1] + cnt[i + 1] * b[i] << ' ';
  }
  std::cout << '\n';
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
