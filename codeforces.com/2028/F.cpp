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

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
  std::vector<int> a(n + 1), mul(n + 1, 1), sum(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mul[i] = mul[i - 1] * a[i] % mod;
    sum[i] = (sum[i - 1] + a[i]) % mod;
  }
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < i; k++) {
        int prv = (j - mul[i] * inv(mul[k]) % mod + mod) % mod;
        // std::cout << 
        if (prv < 0 || prv > m) continue;
        f[i][j] |= f[k][prv];
      }
    }
  }
  std::cout << f[n][m] << '\n';
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