#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s;
  std::cin >> s;
  int a = 0, b = 0;
  for (auto c : s) {
    a += !!isdigit(c);
    b += !!isalpha(c);
  }
  std::cout << a << ' ' << b << '\n';
}

signed main() {
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}