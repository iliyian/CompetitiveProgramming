#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int c0 = 0, c1 = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] % 2) c1++;
    else c0++;
  }
  std::cout << c0 * c1 % mod << '\n';
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