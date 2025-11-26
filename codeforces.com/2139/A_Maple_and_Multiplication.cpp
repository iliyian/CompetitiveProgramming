#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (a == b) {
    std::cout << 0 << '\n';
  } else if (a % b == 0 || b % a == 0) {
    std::cout << 1 << '\n';
  } else {
    std::cout << 2 << '\n';
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