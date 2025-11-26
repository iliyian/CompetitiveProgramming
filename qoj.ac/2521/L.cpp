#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (a >= 30) {
    std::cout << "Alice\n";
  } else if (b >= 30) {
    std::cout << "Bob\n";
  } else {
    if (a >= 21 && a - b >= 2) {
      std::cout << "Alice\n";
    } else if (b >= 21 && b - a >= 2) {
      std::cout << "Bob\n";
    } else {
      std::cout << "Underway\n";
    }
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