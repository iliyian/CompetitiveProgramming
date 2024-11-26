#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  while (std::cin >> str) {
    while (str.back() == '0') str.pop_back();
    std::reverse(str.begin(), str.end());
    std::cout << str << '\n';
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