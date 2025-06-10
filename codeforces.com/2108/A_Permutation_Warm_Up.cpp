#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx += std::abs(i - (n - i + 1));
  }
  std::cout << mx / 2 + 1 << '\n';
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