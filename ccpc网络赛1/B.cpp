#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int x) {
  return qpow(x, mod - 2);
}

int cal(int x) { // 等比数列求和
  return (((qpow(10, x) - 1) % mod) + mod) % mod * inv(9) % mod;
}

void solve() {
  int m;
  std::cin >> m;
  std::vector<int> a(10);
  for (int i = 0; i <= 9; i++) {
    std::cin >> a[i];
  }
  if (m == 1 && a[0]) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 0; // 放非零最小值
  for (int i = 1; i <= 9; i++) {
    if (a[i]) {
      int t = 1; // 最多可几个
      ans = ans * qpow(10, t) % mod + i * cal(t) % mod;
      ans %= mod;
      m -= t;
      a[i] -= t;
      break;
    }
  } // 放0
  int t = std::min(a[0], m);
  ans = ans * qpow(10, t);
  ans %= mod;
  m -= t;
  a[0] -= t;
  for (int i = 1; i <= 9; i++) {
    if (a[i] && m) {
      int t = std::min(a[i], m); // 最多可几个
      ans = ans * qpow(10, t) % mod + i * cal(t) % mod;
      ans %= mod;
      m -= t;
      a[i] -= t;
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
//  freopen("B.i", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
