// date: 2024-04-19 12:35:05
// tag: 组合数，暴力，补集

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
  }
  auto qpow = [&](int a, int b) {
    int ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ans;
  };
  vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  vector<int> mc(n + 1), nc(n + 1);
  mc[0] = nc[0] = 1;
  for (int i = 1; i < n; i++) {
    mc[i] = mc[i - 1] * (m - i + 1) % mod;
    nc[i] = nc[i - 1] * inv[i] % mod;
  }
  auto C = [&mc, &nc](int m, int i) {
    return mc[i] * nc[i] % mod;
  };
  int ans = qpow(k, m);
  for (int i = 0; i < n; i++) {
    ans -= C(m, i) * qpow(k - 1, m - i) % mod;
    ans = (ans % mod + mod) % mod;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}