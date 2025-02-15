#include <bits/stdc++.h>
#include <cctype>
#define int long long

void solve() {
  std::string s;
  int n;
  std::cin >> s >> n;
  for (char c : s) {
    int d = isdigit(c) ? c - '0' : c - 'A' + 10;
    if (d >= n) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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