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
  }
  int cnt = (a[1] == -1 ? 2 : 1);
  int ans = (a[1] == 0 ? 0 : 1);
  int inv2 = qpow(2, mod - 2);
  for (int i = 2; i <= n; i++) {
    if (a[i] == 1) {
      if (a[i - 1] == 0) {
        ans += cnt;
        ans %= mod;
      } else if (a[i - 1] == -1) {
        ans += cnt * inv2 % mod;
        ans %= mod;
      }
    } else if (a[i] == 0) {
    } else {
      ans *= 2;
      ans %= mod;
      if (a[i - 1] == -1) {
        ans = ans + cnt * inv2 % mod;
        ans %= mod;
      } else if (a[i - 1] == 0) {
        ans = ans + cnt;
        ans %= mod;
      }
      cnt *= 2;
      cnt %= mod;
    }
  }
  std::cout << ans << '\n';
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