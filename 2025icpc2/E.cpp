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
  int n, m;
  std::cin >> n >> m;
  if (n % 2 == 1) {
    int ans = (qpow(2, m) - 1 + mod) % mod;
    ans = qpow(ans, n - 1);
    std::cout << ans << '\n';
  } else {
    int ans = (qpow(2, m) - 1 + mod) % mod;
    ans = qpow(ans, n - 1);
    int t = (qpow(2, m) - 1 + mod) % mod;
    t = qpow(t, n / 2);
    if (n / 2 % 2) {
      ans -= t;
      ans = (ans % mod + mod) % mod;
    } else {
      ans += t;
      ans %= mod;
    }
    std::cout << ans << '\n';
  }
}

void solve2() {
  int m = 0;
  int t = (1ll << m);
  for (int n = 1; n <= t; n++) {
    std::vector<int> v;
    int sum = 0;
    auto dfs = [&](auto self, int u) {
      if (u == n + 1) {
        int ans = 0;
        for (int i : v) {
          ans ^= i;
        }
        if (ans == 0) {
          sum++;
        }
        return;
      }
      for (int i = 0; i < t; i++) {
        if (v.empty() || i != v.back()) {
          v.push_back(i);
          self(self, u + 1);
          v.pop_back();
        }
      }
    };
    dfs(dfs, 1);
    std::cout << n << ' ' << m << ' ' << sum << ' ';
    if (n % 2 == 0) {
      // std::cerr << pow(pow(2, m) - 1, n - 1) + pow(pow(2, m) - 1, n / 2) << '\n';
      std::cerr << sum - pow(pow(2, m) - 1, n - 1) << '\n';
    } else {
      std::cout << '\n';
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}