#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int N = 5201314;
std::vector<int> ans(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::cout << ans[n] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  ans[0] = 0;
  int fac = 1;
  for (int i = 1; i <= N; i++) {
    fac = fac * i % mod;
    ans[i] = (ans[i - 1] + fac) % mod * i % mod;
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}