#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  std::set<char> s;
  for (int i = 0; i < str.size(); i += 2) {
    if (str[i] != str[i + 1] || s.count(str[i])) {
      std::cout << "No\n";
      return;
    }
    s.insert(str[i]);
  }
  std::cout << "Yes\n";
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