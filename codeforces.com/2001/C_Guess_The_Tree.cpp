#include <bits/stdc++.h>
#include <ostream>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::set<std::pair<int, int>> s;
  for (int i = 2; i <= n; i++) {
    int u = 1;
    while (1) {
      std::cout << "? " << u << ' ' << i << std::endl;
      int ans;
      std::cin >> ans;
      if (ans == u) {
        s.insert({u, i});
        break;
      } else {
        u = ans;
      }
    }
  }
  std::cout << "! ";
  for (auto [x, y] : s) {
    std::cout << x << ' ' << y << ' ';
  }
  std::cout << std::endl;
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