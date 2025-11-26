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
 * @File    : D_From_1_to_Infinity.cpp
 * @Time    : 2025-11-17 21:08:40
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int ten[18] {}, sum[18] {};

int calc(int mid) {
  int sum = 0;
  for (int i = 0; i < 18; i++) {
    sum += std::max(mid - ten[i] + 1, 0ll);
  }
  return sum;
}

int get(int x) {
  if (x < 10) return x;
  return x % 10 + get(x / 10);
}

int cal(int x) {
  int ans = 0;
  for (int i = 1; i <= x; i++) {
    ans += get(i);
  }
  return ans;
}

int a[100] {}, mi[100] {}, dp[100] {};

void oiwiki(int n, int *ans) {
  int tmp = n;
  int len = 0;
  while (n) a[++len] = n % 10, n /= 10;
  for (int i = len; i >= 1; --i) {
    for (int j = 0; j < 10; j++) ans[j] += dp[i - 1] * a[i];
    for (int j = 0; j < a[i]; j++) ans[j] += mi[i - 1];
    tmp -= mi[i - 1] * a[i], ans[a[i]] += tmp + 1;
    ans[0] -= mi[i - 1];
  }
}

void solve() {
  int k;
  std::cin >> k;
  int l = 0, r = 1e18, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (calc(mid) <= k) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  int res = 0;
  std::string v = std::to_string(ans + 1);
  int d = k - calc(ans);
  for (int i = 0; i < d; i++) {
    res += v[i] - '0';
  }
  int dig[10] {};
  oiwiki(ans, dig);
  for (int i = 0; i < 10; i++) {
    res += i * dig[i];
  }
  std::cout << res << '\n';
  // std::cerr << ans << ' ' << d << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  mi[0] = 1ll;
  for (int i = 1; i <= 13; ++i) {
    dp[i] = dp[i - 1] * 10 + mi[i - 1];
    mi[i] = 10ll * mi[i - 1];
  }

  ten[0] = 1;
  for (int i = 0; i < 17; i++) {
    ten[i + 1] = ten[i] * 10;
    sum[i + 1] = sum[i] * 10 + 45;
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
