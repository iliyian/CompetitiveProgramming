#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  while (std::cin >> str) {
    if (std::stoll(str) < 0) {
      break;
    }
    std::string rev = str;
    std::reverse(str.begin(), str.end());
    std::cout << (rev == str ? "Yes" : "No") << '\n';
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