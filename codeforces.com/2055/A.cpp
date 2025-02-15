#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  std::cout << (std::abs(a - b) % 2 == 0 ? "YES" : "NO") << '\n';
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