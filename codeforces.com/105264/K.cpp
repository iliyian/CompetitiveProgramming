#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char x;
      std::cin >> x;
      a[i][j] = x - '0';
    }
  }
  int mn = 2;
  for (int i = 3; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] != a[mn][j]) {
        if (a[i][j] < a[mn][j]) {
          mn = i;
        }
        break;
      }
    }
  }
  int ans = 0, ten = 1;
  for (int i = n; i >= 1; i--) {
    ans = ans + (ten * a[mn][i] % mod * n % mod);
    ans %= mod;
    ten *= 10;
    ten %= mod;
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("K.in", "r", stdin);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}