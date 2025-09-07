#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int sum = 0;
  for (int i = 1; i <= n - 1; i++) {
    int x;
    std::cin >> x;
    sum += x;
  }
  std::cout << -sum << '\n';
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