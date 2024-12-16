#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  char c1, c2;
  char ch;
  std::cin >> n >> c1 >> c2;
  for (int i = 1; i <= n; i++) {
    std::cin >> ch;
    if (ch != c1) {
      std::cout << c2;
    } else {
      std::cout << c1;
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
