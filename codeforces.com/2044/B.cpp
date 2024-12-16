#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  std::reverse(str.begin(), str.end());
  for (char ch : str) {
    std::cout << (ch == 'p' ? 'q' : ch == 'q' ? 'p' : ch);
  }
  std::cout << '\n';
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