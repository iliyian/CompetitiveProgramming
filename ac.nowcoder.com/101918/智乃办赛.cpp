#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::cout << char((n - 1) / 500 + 'A') << std::setw(3) << std::setfill('0') << (n - 1) % 500 + 1 << '\n';
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