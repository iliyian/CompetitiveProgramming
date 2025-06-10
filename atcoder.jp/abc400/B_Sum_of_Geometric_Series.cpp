#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int cur = 1, sum = 0;
  for (int i = 1; i <= m + 1; i++) {
    sum += cur;
    cur *= n;
    if (sum > 1e9) {
      std::cout << "inf\n";
      return;
    }
  }
  std::cout << sum << '\n';
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