#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (a == b) {
    if (a == 1) {
      std::cout << 1 << '\n';
    } else {
      std::cout << 0 << '\n';
    }
  } else {
    std::cout << b - a << '\n';
  }
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