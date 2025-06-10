// date: 2025-04-08 13:35:54
// tag: 还是比较套路的计数dp，可惜还是状态设置和特殊情况没弄好

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] %= 2;
  }
  int ans = 0;
  std::vector<std::array<std::array<int, 2>, 2>> f(n + 1, {{{0, 0}, {0, 0}}});
  std::vector<std::array<std::array<int, 2>, 2>> s(n + 1, {{{0, 0}, {0, 0}}});
  int cnt0 = 0, cnt1 = 0;
  if (a[1] == 0 && a[2] == 0) {
    f[2][0][0] = 1;
    cnt0 += 2;
  }
  if (a[1] == 0 && a[2] == 1) {
    f[2][0][1] = 1;
    cnt0++, cnt1++;
  }
  if (a[1] == 1 && a[2] == 0) {
    f[2][1][0] = 1;
    cnt0++, cnt1++;
  }
  if (a[1] == 1 && a[2] == 1) {
    f[2][1][1] = 1;
    cnt1 += 2;
  }
  int t = 0;
  for (int i = 3; i <= n; i++) {
    f[i] = f[i - 1];
    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 2; y++) {
        if ((a[i] + x + y) % 2 == 0) {
          f[i][y][a[i]] += f[i - 1][x][y] % mod;
          f[i][y][a[i]] %= mod;
        }
      }
    }
    f[i][0][a[i]] += cnt0;
    f[i][1][a[i]] += cnt1;
    t += cnt0 + cnt1;
    t %= mod;
    cnt0 += !a[i];
    cnt1 += a[i];
    // for (int x = 0; x < 2; x++) {
    //   for (int y = 0; y < 2; y++) {
    //     std::cerr << f[i][x][y] << ' ';
    //   }
    // }
    // std::cerr << '\n';
  }
  for (int x = 0; x < 2; x++) {
    for (int y = 0; y < 2; y++) {
      ans += f[n][x][y];
      ans %= mod;
    }
  }
  std::cout << ((ans - t + mod) % mod + mod - 1) % mod << '\n';
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