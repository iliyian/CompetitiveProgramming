#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

void solve() {
  int t;
  std::cin >> t;
  std::vector<int> a(t + 1), b(t + 1);
  a[0] = 1, b[0] = 0;
  for (int i = 1; i <= t; i++) {
    a[i] = (a[i - 1] * a[i - 1] % mod + 2 * a[i - 1] % mod * b[i - 1] % mod) % mod;
    b[i] = (a[i - 1] * a[i - 1] % mod + b[i - 1] * b[i - 1] % mod) % mod;
  }
  std::cout << a[t] << ' ' << b[t] << '\n';
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