#include <bits/stdc++.h>
#include <cctype>
#define int long long

void solve() {
  char c;
  while (std::cin >> c, c < 'C' || c > 'X');
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    if (std::abs(ch - c) <= 2) {
      std::cout << ch;
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