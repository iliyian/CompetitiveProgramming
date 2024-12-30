#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  char ch;
  std::cin >> ch;
  std::cout << char(isupper(ch) ? (ch - 'A' + 1) % 26 + 'a' : (ch - 'a' + 25) % 26 + 'A') << '\n';
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