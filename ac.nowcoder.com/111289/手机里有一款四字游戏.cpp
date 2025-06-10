#include <bits/stdc++.h>
#define int long long

void solve() {
  char a, b;
  int x, y;
  std::cin >> a >> x >> b >> y;
  if (a == b || std::abs(a - b) == 1) {
    std::cout << "YES\n";
    return;
  }
  std::cout << "NO\n";
  if (a > b) {
    std::cout << (a - b - 2) * 5 + 6 - y << '\n';
  } else {
    std::cout << (b - a - 2) * 5 + 6 - x << '\n';
  }
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