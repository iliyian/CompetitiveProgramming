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
  std::vector<int> l = {0}, r = {0};
  for (int i = 1; i <= n; i++) {
    if (a[i] > l.back()) {
      l.push_back(a[i]);
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] > r.back()) {
      r.push_back(a[i]);
    }
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(l.size())), g(n + 2, std::vector<int>(r.size()));
  f[0][0] = g[n + 1][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < l.size(); j++) {
      f[i][j] = f[i - 1][j];
      if (a[i] <= l[j]) {
        f[i][j] *= 2;
      }
      if (a[i] == l[j]) {
        f[i][j] += f[i - 1][j - 1];
      }
      f[i][j] %= mod;
      std::cerr << f[i][j] << ' ';
    }
    std::cerr << '\n';
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < r.size(); j++) {
      g[i][j] = g[i + 1][j];
      if (a[i] <= r[j]) {
        g[i][j] *= 2;
      }
      if (a[i] == r[j]) {
        g[i][j] += g[i + 1][j - 1];
      }
      g[i][j] %= mod;
      std::cerr << g[i][j] << ' ';
    }
    std::cerr << '\n';
  }
  std::cerr << '\n';
  int mid = l.back();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == mid) {
      for (int j = i; j <= n; j++) {
        if (a[j] == mid) {
          // ans += f[i - 1][l.size() - 2] * ((g[i].back() - g[i + 1].back() + mod) % mod) % mod;
          ans += f[i][l.size() - 2] * g[j][r.size() - 2] % mod * qpow(2, std::max(0ll, j - i - 1)) % mod;
          ans %= mod;
        }
      }
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