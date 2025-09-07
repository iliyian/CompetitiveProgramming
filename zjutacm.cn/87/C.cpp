#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, s, k;
  std::cin >> n >> s >> k;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int p, q;
    std::cin >> p >> q;
    sum += p * q;
  }
  std::cout << sum + (sum >= s ? 0 : k) << '\n';
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