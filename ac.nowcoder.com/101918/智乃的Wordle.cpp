#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == s[i]) std::cout << "g";
    else if (s.find(t[i]) != s.npos) std::cout << "y";
    else std::cout << "r";
  }
  std::cout << '\n' << (s == t ? "congratulations" : "defeat") << '\n';
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