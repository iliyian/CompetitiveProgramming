#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (b == 1) {
    std::cout << -1 << '\n';
    return;
  }
  if (b > a) {
    std::cout << 2 << '\n';
  } else if (a >= b + 2) {
    std::cout << 3 << '\n';
  } else {
    std::cout << -1 << '\n';
  }
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