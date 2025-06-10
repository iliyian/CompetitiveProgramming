#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6, mod = 998244353;
int ans[N + 1], p[N + 1];

void solve() {
  int x;
  std::cin >> x;
  std::cout << ans[x] * p[x - 1] % mod << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  ans[1] = p[0] = p[1] = 1;
  for (int i = 2; i <= N; i++) {
    p[i] = p[i - 1] * i % mod;
    ans[i] = ans[i - 1] * 233 % mod + 1;
    ans[i] %= mod;
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}